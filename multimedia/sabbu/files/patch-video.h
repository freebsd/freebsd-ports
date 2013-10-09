--- Source/video.h.orig	2005-07-14 12:52:07.000000000 -0300
+++ Source/video.h	2013-10-08 23:10:25.214159730 -0300
@@ -23,11 +23,13 @@
 };
 
 #else
+extern "C" {
 #ifndef _WINDOWS
-#include <ffmpeg/avformat.h>
+#include <libavformat/avformat.h>
 #else
 #include "video_ffmpeg.h"
 #endif
+}
 #endif
 
 void video_uninit();
