--- import/decode_dv.c.orig	Sun Aug  8 22:03:19 2004
+++ import/decode_dv.c	Sun Aug  8 22:03:43 2004
@@ -37,8 +37,8 @@
 #include "transcode.h"
 #include "ioaux.h"
 
-#define DV_PAL_SIZE    frame_size_625_50
-#define DV_NTSC_SIZE   frame_size_525_60
+#define DV_PAL_SIZE    (12 * 150 * 80)
+#define DV_NTSC_SIZE   (10 * 150 * 80)
 #define DV_HEADER_SIZE header_size
 
 static int verbose=TC_QUIET;
