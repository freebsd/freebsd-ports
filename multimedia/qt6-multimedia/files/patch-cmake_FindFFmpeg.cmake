--- cmake/FindFFmpeg.cmake.orig	2024-11-22 07:31:25 UTC
+++ cmake/FindFFmpeg.cmake
@@ -255,7 +255,7 @@ function(__ffmpeg_internal_set_dependencies _component
 
     # The pkgconfig directory is always in lib/pkgconfig/, even on Windows
     # where libs and dlls are in bin/
-    set(PC_FILE ${${_component}_LIBRARY_DIR}/../lib/pkgconfig/lib${lib}.pc)
+    set(PC_FILE ${${_component}_LIBRARY_DIR}/../libdata/pkgconfig/lib${lib}.pc)
 
     if(EXISTS ${PC_FILE})
         file(READ ${PC_FILE} pcfile)
