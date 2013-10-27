--- ./lives-plugins/plugins/decoders/asf_decoder.c.orig	2012-09-17 16:20:55.000000000 +0200
+++ ./lives-plugins/plugins/decoders/asf_decoder.c	2013-10-27 21:18:00.380266194 +0100
@@ -30,11 +30,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
-#ifndef IS_MINGW
-#ifndef IS_SOLARIS
-#include <endian.h>
-#endif
-#endif
+#include <ctype.h>
 #include <sys/stat.h>
 
 const char *plugin_version="LiVES asf/wmv decoder version 1.0";
@@ -57,11 +53,35 @@
 #endif
 
 #include <libavformat/avformat.h>
+#include <libavcodec/version.h>
 #include <libavutil/avstring.h>
 
 #include "decplugin.h"
 #include "asf_decoder.h"
 
+#if (LIBAVCODEC_VERSION_MAJOR > 54)
+#define CodecID AVCodecID
+#define CODEC_ID_NONE AV_CODEC_ID_NONE
+#define CODEC_ID_WMV1 AV_CODEC_ID_WMV1
+#define CODEC_ID_WMV2 AV_CODEC_ID_WMV2
+#define CODEC_ID_WMV3 AV_CODEC_ID_WMV3
+#define CODEC_ID_DVVIDEO AV_CODEC_ID_DVVIDEO
+#define CODEC_ID_MPEG4 AV_CODEC_ID_MPEG4
+#define CODEC_ID_H264 AV_CODEC_ID_H264
+#define CODEC_ID_MPEG1VIDEO AV_CODEC_ID_MPEG1VIDEO
+#define CODEC_ID_MPEG2VIDEO AV_CODEC_ID_MPEG2VIDEO
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
+
 
 static enum CodecID ff_codec_get_id(const AVCodecTag *tags, unsigned int tag)
 {
@@ -2003,7 +2023,8 @@
     return FALSE;
   }
 
-  if ((retval=avcodec_open(vidst->codec, codec)) < 0) {
+
+  if ((retval=avcodec_open2(vidst->codec, codec, NULL)) < 0) {
     fprintf(stderr, "asf_decoder: Could not open avcodec context (%d) %d\n",retval,vidst->codec->frame_number);
     detach_stream(cdata);
     return FALSE;
@@ -2323,6 +2344,9 @@
   cdata->asigned=TRUE;
   cdata->ainterleaf=TRUE;
 
+  av_free(priv->picture);
+  priv->picture=NULL;
+
   return cdata;
 }
 
@@ -2470,6 +2494,7 @@
     priv->ctx->skip_frame=AVDISCARD_NONREF;
 
     priv->last_frame=tframe;
+    if (priv->picture==NULL) priv->picture = avcodec_alloc_frame();
 
 
     // do this until we reach target frame //////////////
@@ -2520,7 +2545,7 @@
 
   }
 
-  if (pixel_data==NULL) return TRUE;
+  if (priv->picture==NULL||pixel_data==NULL) return TRUE;
 
   if (priv->black_fill) btop=cdata->frame_height;
 
