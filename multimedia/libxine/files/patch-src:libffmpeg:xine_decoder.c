--- src/libffmpeg/xine_decoder.c.orig	Fri Aug  2 00:26:53 2002
+++ src/libffmpeg/xine_decoder.c	Mon Aug  5 22:56:40 2002
@@ -39,8 +39,8 @@
 #include "metronom.h"
 #include "xineutils.h"
 
-#include "libavcodec/avcodec.h"
-#include "libavcodec/dsputil.h"
+#include <ffmpeg/avcodec.h>
+#include <ffmpeg/dsputil.h>
 
 /*
 #define LOG
@@ -379,29 +379,6 @@
 
 static char *ff_get_id(void) {
   return "ffmpeg video decoder";
-}
-
-void avcodec_register_all(void)
-{
-    static int inited = 0;
-    
-    if (inited != 0)
-	return;
-    inited = 1;
-
-    /* decoders */
-    register_avcodec(&h263_decoder);
-    register_avcodec(&mpeg4_decoder);
-    register_avcodec(&msmpeg4v1_decoder);
-    register_avcodec(&msmpeg4v2_decoder);
-    register_avcodec(&msmpeg4v3_decoder);
-    register_avcodec(&wmv1_decoder);
-    register_avcodec(&wmv2_decoder);
-    register_avcodec(&mpeg_decoder);
-    register_avcodec(&h263i_decoder);
-    register_avcodec(&rv10_decoder);
-    register_avcodec(&svq1_decoder);
-    register_avcodec(&mjpeg_decoder);
 }
 
 static void init_routine(void) {
