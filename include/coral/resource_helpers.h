#ifndef CORAL_RESOURCE_HELPERS_H
#define CORAL_RESOURCE_HELPERS_H

#include <osgDB/Registry>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <filesystem>

namespace coral
{

inline void addResourcePath(const std::string &path)
{
  static auto &paths(osgDB::Registry::instance()->getDataFilePathList());
  if(std::find(paths.begin(), paths.end(), path) == paths.end())
    paths.push_back(path);
}

void initCoralResources();

// resolve the path (package:// - compatible) and returns the corresponding node
osg::Node *extractMesh(const std::string &path);

}

#endif // CORAL_RESOURCE_HELPERS_H
