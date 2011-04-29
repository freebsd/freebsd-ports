--- src/zm_ffmpeg_camera.cpp.orig	2009-05-25 22:04:00.000000000 +0400
+++ src/zm_ffmpeg_camera.cpp	2011-04-08 17:48:07.366805007 +0400
@@ -18,7 +18,7 @@
 // 
 
 #include "zm.h"
-
+#include <errno.h> 
 #if HAVE_LIBAVFORMAT
 
 #include "zm_ffmpeg_camera.h"
