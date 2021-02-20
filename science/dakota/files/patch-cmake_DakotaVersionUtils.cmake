--- cmake/DakotaVersionUtils.cmake.orig	2021-02-10 05:46:56 UTC
+++ cmake/DakotaVersionUtils.cmake
@@ -28,7 +28,7 @@ macro(dakota_version_from_git)
 
   # Building in a Git repo or a source package?
   set(DAKOTA_VERSION_file_path)
-  set(DAKOTA_GIT_checkout FALSE)
+  set(DAKOTA_GIT_checkout TRUE)
 
   if(EXISTS ${Dakota_SOURCE_DIR}/.git)
 
