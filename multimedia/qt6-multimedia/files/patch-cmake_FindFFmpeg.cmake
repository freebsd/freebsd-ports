--- cmake/FindFFmpeg.cmake.orig	2024-06-03 15:20:28 UTC
+++ cmake/FindFFmpeg.cmake
@@ -253,7 +253,7 @@ function(__ffmpeg_internal_set_dependencies _component
 # and adds them to the target library.
 function(__ffmpeg_internal_set_dependencies _component)
   string(TOLOWER ${_component} lib)
-  set(PC_FILE ${${_component}_LIBRARY_DIR}/pkgconfig/lib${lib}.pc)
+  set(PC_FILE ${${_component}_LIBRARY_DIR}/../libdata/pkgconfig/lib${lib}.pc)
   if(EXISTS ${PC_FILE})
     file(READ ${PC_FILE} pcfile)
 
