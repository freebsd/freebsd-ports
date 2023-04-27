--- cmake/FindFFmpeg.cmake.orig	2023-04-25 07:25:17 UTC
+++ cmake/FindFFmpeg.cmake
@@ -26,6 +26,8 @@
 # Redistribution and use is allowed according to the terms of the BSD license.
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
+
 include(FindPackageHandleStandardArgs)
 
 # The default components were taken from a survey over other FindFFMPEG.cmake files
