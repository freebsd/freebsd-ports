--- player/plugin/video/ffmpeg/ffmpeg.h.orig	2007-07-02 22:26:03.000000000 +0200
+++ player/plugin/video/ffmpeg/ffmpeg.h	2009-08-12 11:11:12.005600087 +0200
@@ -28,8 +28,10 @@
 extern "C" {
 #ifdef HAVE_FFMPEG_INSTALLED
 #include <ffmpeg/avcodec.h>
+#include <ffmpeg/swscale.h>
 #else
 #include <avcodec.h>
+#include <swscale.h>
 #endif
 }
 #include <mp4av.h>
