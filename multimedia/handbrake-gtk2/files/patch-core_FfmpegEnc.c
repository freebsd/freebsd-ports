--- core/FfmpegEnc.c.orig	Mon Nov 22 21:55:47 2004
+++ core/FfmpegEnc.c	Mon Nov 22 21:28:42 2004
@@ -7,7 +7,7 @@
 #include "HBInternal.h"

 /* libavcodec */
-#include "ffmpeg/avcodec.h"
+#include "avcodec.h"

 struct HBWork
 {
