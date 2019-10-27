--- src/common/protobuf_utils.cpp.orig	2019-10-01 20:45:10 UTC
+++ src/common/protobuf_utils.cpp
@@ -1375,7 +1375,7 @@ void addMinimumCapability(
     const MasterInfo::Capability::Type& capability)
 {
   int capabilityIndex =
-    find_if(
+    std::find_if(
         capabilities->begin(),
         capabilities->end(),
         [&](const Registry::MinimumCapability& mc) {
@@ -1396,7 +1396,7 @@ void removeMinimumCapability(
     const MasterInfo::Capability::Type& capability)
 {
   int capabilityIndex =
-    find_if(
+    std::find_if(
         capabilities->begin(),
         capabilities->end(),
         [&](const Registry::MinimumCapability& mc) {
