--- src/libffmpeg/xine_decoder.c.orig	Thu Jan 30 23:25:11 2003
+++ src/libffmpeg/xine_decoder.c	Thu Jan 30 23:25:14 2003
@@ -40,8 +40,8 @@
 #include "xineutils.h"
 #include "math.h"
 
-#include "libavcodec/avcodec.h"
-#include "libavcodec/dsputil.h"
+#include <ffmpeg/avcodec.h>
+#include <ffmpeg/dsputil.h>
 
 /*
 #define LOG
