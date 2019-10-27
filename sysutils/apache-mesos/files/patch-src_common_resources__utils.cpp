--- src/common/resources_utils.cpp.orig	2019-10-01 20:28:10 UTC
+++ src/common/resources_utils.cpp
@@ -914,7 +914,7 @@ Resources shrinkResources(const Resources& resources, 
   // TODO(mzhu): Add a `shuffle()` method in `Resources` to avoid this copy.
   google::protobuf::RepeatedPtrField<Resource> resourceVector = resources;
 
-  random_shuffle(resourceVector.begin(), resourceVector.end());
+  std::random_shuffle(resourceVector.begin(), resourceVector.end());
 
   Resources result;
   foreach (Resource& resource, resourceVector) {
@@ -947,7 +947,7 @@ Resources shrinkResources(const Resources& resources, 
   // TODO(mzhu): Add a `shuffle()` method in `Resources` to avoid this copy.
   google::protobuf::RepeatedPtrField<Resource> resourceVector = resources;
 
-  random_shuffle(resourceVector.begin(), resourceVector.end());
+  std::random_shuffle(resourceVector.begin(), resourceVector.end());
 
   Resources result;
   foreach (Resource resource, resourceVector) {
