--- src/zm_local_camera.h.orig	2016-10-03 17:21:50 UTC
+++ src/zm_local_camera.h
@@ -41,6 +41,11 @@
 #define VIDEO_MAX_FRAME               32
 #endif
 
+// Required on systems with v4l1 but without v4l2 headers
+#ifndef VIDEO_MAX_FRAME
+#define VIDEO_MAX_FRAME	32
+#endif
+
 #include "zm_ffmpeg.h"
 
 //
