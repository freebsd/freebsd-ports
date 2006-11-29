--- src/libffmpeg/libavcodec/huffyuv.c.orig	Thu Sep 28 13:25:07 2006
+++ src/libffmpeg/libavcodec/huffyuv.c	Thu Sep 28 13:25:32 2006
@@ -30,6 +30,7 @@
 #include "bitstream.h"
 #include "avcodec.h"
 #include "dsputil.h"
+#include "xine_internal.h"
 
 #define VLC_BITS 11
 
