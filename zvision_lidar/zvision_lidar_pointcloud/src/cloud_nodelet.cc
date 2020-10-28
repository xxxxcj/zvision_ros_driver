/*
 *  Copyright (C) 2012 Austin Robot Technology, Jack O'Quin
 *  Copyright (C) 2019 Zvision
 *  License: Modified BSD Software License Agreement
 *
 *  $Id$
 */

/** @file

    This ROS nodelet converts raw ZVISION 3D LIDAR packets to a
    PointCloud2.

*/

#include <ros/ros.h>
#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include "convert.h"

namespace zvision_lidar_pointcloud
{
class CloudNodelet : public nodelet::Nodelet
{
public:
  CloudNodelet()
  {
  }
  ~CloudNodelet()
  {
  }

private:
  virtual void onInit();
  boost::shared_ptr<Convert> conv_;
};

/** @brief Nodelet initialization. */
void CloudNodelet::onInit()
{
  conv_.reset(new Convert(getNodeHandle(), getPrivateNodeHandle()));
}

}  // namespace velodyne_pointcloud

// Register this plugin with pluginlib.  Names must match nodelets.xml.
//
// parameters: class type, base class type
PLUGINLIB_EXPORT_CLASS(zvision_lidar_pointcloud::CloudNodelet, nodelet::Nodelet)