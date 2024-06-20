--- src/plugins/multimedia/ffmpeg/cmake/QtAddFFmpegStubs.cmake.orig	2024-06-03 15:20:28 UTC
+++ src/plugins/multimedia/ffmpeg/cmake/QtAddFFmpegStubs.cmake
@@ -17,7 +17,7 @@ function(qt_internal_multimedia_check_ffmpeg_stubs_con
 endfunction()
 
 function(qt_internal_multimedia_check_ffmpeg_stubs_configuration)
-    if (NOT LINUX AND NOT ANDROID)
+    if (NOT UNIX AND NOT ANDROID)
         message(FATAL_ERROR "Currently, stubs are supported on Linux and Android")
     endif()
 
