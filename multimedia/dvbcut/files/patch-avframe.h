--- src/avframe.h~	2007-04-13 19:36:27 +0200
+++ src/avframe.h	2007-07-17 01:08:23 +0200
@@ -19,7 +19,9 @@
 #ifndef _DVBCUT_AVFRAME_H
 #define _DVBCUT_AVFRAME_H
 
+extern "C" {
 #include <ffmpeg/avcodec.h>
+}
 
 class QImage;
 
