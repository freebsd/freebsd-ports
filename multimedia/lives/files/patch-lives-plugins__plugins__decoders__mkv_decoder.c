--- ./lives-plugins/plugins/decoders/mkv_decoder.c.orig	2013-06-17 03:25:33.000000000 +0200
+++ ./lives-plugins/plugins/decoders/mkv_decoder.c	2013-10-15 12:40:20.000000000 +0200
@@ -36,6 +36,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <ctype.h>
 #include <sys/stat.h>
 
 const char *plugin_version="LiVES mkv decoder version 1.2";
@@ -63,17 +64,61 @@
 
 #include <libavformat/avformat.h>
 #include <libavutil/avstring.h>
+#include <libavcodec/version.h>
 #include <libavutil/mem.h>
 
 #include "decplugin.h"
 
-#include "mkv_decoder.h"
-
 #include <libavutil/intfloat_readwrite.h>
 #include <libavutil/intreadwrite.h>
 #include <libavutil/lzo.h>
 #include <libavutil/dict.h>
 
+
+#if (LIBAVCODEC_VERSION_MAJOR > 54)
+#define CodecID AVCodecID
+#define CODEC_ID_NONE AV_CODEC_ID_NONE
+#define CODEC_ID_TEXT AV_CODEC_ID_TEXT
+#define CODEC_ID_SSA AV_CODEC_ID_SSA
+#define CODEC_ID_VP8 AV_CODEC_ID_VP8
+#define CODEC_ID_THEORA AV_CODEC_ID_THEORA
+#define CODEC_ID_SNOW AV_CODEC_ID_SNOW
+#define CODEC_ID_DIRAC AV_CODEC_ID_DIRAC
+#define CODEC_ID_MJPEG AV_CODEC_ID_MJPEG
+#define CODEC_ID_MPEG1VIDEO AV_CODEC_ID_MPEG1VIDEO
+#define CODEC_ID_MPEG2VIDEO AV_CODEC_ID_MPEG2VIDEO
+#define CODEC_ID_MPEG4 AV_CODEC_ID_MPEG4
+#define CODEC_ID_H264 AV_CODEC_ID_H264
+#define CODEC_ID_MSMPEG4V3 AV_CODEC_ID_MSMPEG4V3
+#define CODEC_ID_RV10 AV_CODEC_ID_RV10
+#define CODEC_ID_RV20 AV_CODEC_ID_RV20
+#define CODEC_ID_RV30 AV_CODEC_ID_RV30
+#define CODEC_ID_RV40 AV_CODEC_ID_RV40
+#define CODEC_ID_RAWVIDEO AV_CODEC_ID_RAWVIDEO
+#endif
+
+#ifndef FF_API_AVCODEC_OPEN
+#define FF_API_AVCODEC_OPEN     (LIBAVCODEC_VERSION_MAJOR < 55)
+#endif
+
+
+#if FF_API_AVCODEC_OPEN
+#define avcodec_open2(a, b, c) avcodec_open(a, b)
+#endif
+
+#ifndef FF_API_ALLOC_CONTEXT
+#define FF_API_ALLOC_CONTEXT    (LIBAVCODEC_VERSION_MAJOR < 55)
+#endif
+
+
+#if FF_API_ALLOC_CONTEXT
+#define avcodec_alloc_context3(a) avcodec_alloc_context()
+#endif
+
+
+#include "mkv_decoder.h"
+
+
 #if CONFIG_ZLIB
 #include <zlib.h>
 #endif
@@ -96,7 +141,6 @@
 };
 
 
-
 static enum CodecID ff_codec_get_id(const AVCodecTag *tags, unsigned int tag)
 {
   int i;
@@ -1748,9 +1792,9 @@
     return FALSE;
   }
 
-  priv->ctx = ctx = avcodec_alloc_context();
+  priv->ctx = ctx = avcodec_alloc_context3(codec);
 
-  if (avcodec_open(ctx, codec) < 0) {
+  if (avcodec_open2(ctx, codec, NULL) < 0) {
     fprintf(stderr, "mkv_decoder: Could not open avcodec context for codec\n");
     detach_stream(cdata);
     return FALSE;
@@ -2076,6 +2120,9 @@
   cdata->asigned=TRUE;
   cdata->ainterleaf=TRUE;
 
+  av_free(priv->picture);
+  priv->picture=NULL;
+
   return cdata;
 }
 
@@ -2604,6 +2651,7 @@
     //priv->ctx->skip_frame=AVDISCARD_NONREF;
 
     priv->last_frame=tframe;
+    if (priv->picture==NULL) priv->picture = avcodec_alloc_frame();
 
     // do this until we reach target frame //////////////
 
@@ -2640,7 +2688,7 @@
 
   }
 
-  if (pixel_data==NULL) return TRUE;
+  if (priv->picture==NULL||pixel_data==NULL) return TRUE;
   
   for (p=0;p<nplanes;p++) {
     dst=pixel_data[p];
