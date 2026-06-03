--- cmake/FindFFmpeg.cmake.orig	2025-08-15 19:16:13 UTC
+++ cmake/FindFFmpeg.cmake
@@ -276,7 +276,7 @@ function(__ffmpeg_internal_set_dependencies _component
     if (WIN32)
         set(PC_FILE ${${_component}_LIBRARY_DIR}/../lib/pkgconfig/lib${lib}.pc)
     else()
-        set(PC_FILE ${${_component}_LIBRARY_DIR}/pkgconfig/lib${lib}.pc)
+        set(PC_FILE ${${_component}_LIBRARY_DIR}/../libdata/pkgconfig/lib${lib}.pc)
     endif()
 
     if(EXISTS ${PC_FILE})
