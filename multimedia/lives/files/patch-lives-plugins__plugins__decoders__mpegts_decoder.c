--- ./lives-plugins/plugins/decoders/mpegts_decoder.c.orig	2013-03-13 04:33:33.000000000 +0100
+++ ./lives-plugins/plugins/decoders/mpegts_decoder.c	2013-10-27 21:18:32.478233114 +0100
@@ -27,11 +27,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <ctype.h>
 #include <sys/stat.h>
 
-#ifndef IS_MINGW
-#include <endian.h>
-#endif
 
 const char *plugin_version="LiVES mpegts decoder version 1.0";
 
@@ -55,27 +53,69 @@
 
 #include "decplugin.h"
 
+
 #include <libavformat/avformat.h>
 #include <libavutil/opt.h>
 #include <libavutil/crc.h>
 #include <libavutil/avstring.h>
 #include <libavutil/mem.h>
 #include <libavcodec/avcodec.h>
+#include <libavcodec/version.h>
 
 #include "mpegts_decoder.h"
 
+#ifndef FF_API_OLD_AVOPTIONS
+#define FF_API_OLD_AVOPTIONS            (LIBAVUTIL_VERSION_MAJOR < 53)
+#endif
+
+#if FF_API_OLD_AVOPTIONS
+#define AV_OPT_TYPE_INT FF_OPT_TYPE_INT
+#endif
 
 #ifndef offsetof
-#    define offsetof(T, F) ((unsigned int)((char *)&((T *)0)->F))
+#define offsetof(T, F) ((unsigned int)((char *)&((T *)0)->F))
 #endif
 
-#ifndef AV_OPT_TYPE_INT
-#define AV_OPT_TYPE_INT FF_OPT_TYPE_INT
+
+#if (LIBAVCODEC_VERSION_MAJOR > 54)
+#define CodecID AVCodecID
+#define CODEC_ID_NONE AV_CODEC_ID_NONE
+#define CODEC_ID_MPEG1VIDEO AV_CODEC_ID_MPEG1VIDEO
+#define CODEC_ID_MPEG2VIDEO AV_CODEC_ID_MPEG2VIDEO
+#define CODEC_ID_MPEG4 AV_CODEC_ID_MPEG4
+#define CODEC_ID_H264 AV_CODEC_ID_H264
+#define CODEC_ID_DIRAC AV_CODEC_ID_DIRAC
+#define CODEC_ID_MP3 AV_CODEC_ID_MP3
+#define CODEC_ID_AAC AV_CODEC_ID_AAC
+#define CODEC_ID_VC1 AV_CODEC_ID_VC1
+#define CODEC_ID_PCM_BLURAY AV_CODEC_ID_PCM_BLURAY
+#define CODEC_ID_AC3 AV_CODEC_ID_AC3
+#define CODEC_ID_EAC3 AV_CODEC_ID_EAC3
+#define CODEC_ID_DTS AV_CODEC_ID_DTS
+#define CODEC_ID_TRUEHD AV_CODEC_ID_TRUEHD
+#define CODEC_ID_S302M AV_CODEC_ID_S302M
+#define CODEC_ID_DVB_TELETEXT AV_CODEC_ID_DVB_TELETEXT
+#define CODEC_ID_DVB_SUBTITLE AV_CODEC_ID_DVB_SUBTITLE
+#endif
+
+#ifndef FF_API_AVCODEC_OPEN
+#define FF_API_AVCODEC_OPEN     (LIBAVCODEC_VERSION_MAJOR < 55)
 #endif
 
 
+#if FF_API_AVCODEC_OPEN
+#define avcodec_open2(a, b, c) avcodec_open(a, b)
+#endif
 
 
+#ifndef FF_API_ALLOC_CONTEXT
+#define FF_API_ALLOC_CONTEXT    (LIBAVCODEC_VERSION_MAJOR < 55)
+#endif
+
+
+#if FF_API_ALLOC_CONTEXT
+#define avcodec_alloc_context3(a) avcodec_alloc_context()
+#endif
 
 /**
  * Read 1-25 bits.
@@ -3064,9 +3104,9 @@
     return FALSE;
   }
 
-  priv->ctx = ctx = avcodec_alloc_context();
+  priv->ctx = ctx = avcodec_alloc_context3(codec);
 
-  if (avcodec_open(ctx, codec) < 0) {
+  if (avcodec_open2(ctx, codec, NULL) < 0) {
     fprintf(stderr, "mpegts_decoder: Could not open avcodec context\n");
     detach_stream(cdata);
     return FALSE;
@@ -3292,6 +3332,9 @@
   fprintf(stderr,"fps is %.4f %ld %ld %ld\n",cdata->fps,cdata->nframes,ldts,priv->start_dts);
 #endif
 
+  av_free(priv->picture);
+  priv->picture=NULL;
+
   return TRUE;
 }
 
@@ -3517,6 +3560,7 @@
       //priv->ctx->skip_frame=AVDISCARD_NONREF;
 
       priv->last_frame=tframe;
+      if (priv->picture==NULL) priv->picture = avcodec_alloc_frame();
 
       // do this until we reach target frame //////////////
 
@@ -3554,7 +3598,7 @@
 
     }
 
-    if (pixel_data==NULL) return TRUE;
+    if (priv->picture==NULL||pixel_data==NULL) return TRUE;
 
     for (p=0;p<nplanes;p++) {
       dst=pixel_data[p];
