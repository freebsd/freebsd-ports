--- libaf/af_lavcac3enc.c.orig	2013-07-09 16:33:12 UTC
+++ libaf/af_lavcac3enc.c
@@ -27,7 +27,6 @@
 #include <assert.h>

 #include <libavcodec/avcodec.h>
-#include <libavutil/audioconvert.h>
 #include <libavutil/error.h>
 #include <libavutil/intreadwrite.h>
 #include <libavutil/mem.h>
@@ -219,7 +218,7 @@ static void uninit(struct af_instance_s*
             av_free(s->lavc_actx);
         }
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(54, 28, 0)
-        avcodec_free_frame(&s->frame);
+        av_frame_free(&s->frame);
 #else
         av_freep(&s->frame);
 #endif
@@ -398,7 +397,7 @@ static int af_open(af_instance_t* af){
         mp_tmsg(MSGT_AFILTER, MSGL_ERR, "Audio LAVC, couldn't allocate context!\n");
         return AF_ERROR;
     }
-    s->frame = avcodec_alloc_frame();
+    s->frame = av_frame_alloc();
     if (!s->frame)
         return AF_ERROR;
     const enum AVSampleFormat *fmts = s->lavc_acodec->sample_fmts;
