--- src/media_object.cpp.orig	2013-10-07 13:20:40.603922682 -0300
+++ src/media_object.cpp	2013-10-07 13:21:13.558920266 -0300
@@ -56,6 +56,10 @@
 
 #include "media_object.h"
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000
+#endif
+
 
 // The read thread.
 // This thread reads packets from the AVFormatContext and stores them in the
