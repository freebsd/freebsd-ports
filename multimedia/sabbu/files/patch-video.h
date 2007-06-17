--- Source/video.h.orig	Thu Jul 14 17:52:07 2005
+++ Source/video.h	Sun Jun 17 08:57:32 2007
@@ -23,11 +23,13 @@
 };
 
 #else
+extern "C" {
 #ifndef _WINDOWS
 #include <ffmpeg/avformat.h>
 #else
 #include "video_ffmpeg.h"
 #endif
+}
 #endif
 
 void video_uninit();
