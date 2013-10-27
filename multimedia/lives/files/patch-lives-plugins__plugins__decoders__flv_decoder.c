--- ./lives-plugins/plugins/decoders/flv_decoder.c.orig	2013-06-17 03:25:02.000000000 +0200
+++ ./lives-plugins/plugins/decoders/flv_decoder.c	2013-10-15 12:40:21.000000000 +0200
@@ -59,10 +59,34 @@
 #include <libavformat/avformat.h>
 #include <libavutil/avstring.h>
 #include <libavcodec/avcodec.h>
+#include <libavcodec/version.h>
 
 #include "decplugin.h"
 #include "flv_decoder.h"
 
+
+#if (LIBAVCODEC_VERSION_MAJOR > 54)
+#define CodecID AVCodecID
+#define CODEC_ID_NONE AV_CODEC_ID_NONE
+#define CODEC_ID_FLV1 AV_CODEC_ID_FLV1
+#define CODEC_ID_FLASHSV AV_CODEC_ID_FLASHSV
+#define CODEC_ID_FLASHSV2 AV_CODEC_ID_FLASHSV2
+#define CODEC_ID_VP6A AV_CODEC_ID_VP6A
+#define CODEC_ID_VP6F AV_CODEC_ID_VP6F
+#define CODEC_ID_H264 AV_CODEC_ID_H264
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
+
 ////////////////////////////////////////////////////////////////////////////
 
 
@@ -528,7 +552,7 @@
   double num_val,fps;
 
   AVCodec *codec=NULL;
-  AVCodecContext *ctx;
+  AVCodecContext *ctx=NULL;
 
   boolean got_picture=FALSE,got_avcextradata=FALSE;
 
@@ -754,7 +778,7 @@
 
   if (!hasaudio) got_astream=TRUE;
 
-  priv->ctx=ctx = avcodec_alloc_context();
+  priv->ctx = NULL;
 
   sprintf(cdata->audio_name,"%s","");
 
@@ -883,6 +907,9 @@
 	priv->pack_offset=2;
 	break;
       case FLV_CODECID_VP6A  :
+	codec = avcodec_find_decoder(CODEC_ID_VP6A);
+	priv->ctx = ctx = avcodec_alloc_context3(codec);
+
 	sprintf(cdata->video_name,"%s","vp6a");
 	cdata->offs_x=(pack.data[1]&0X0F)>>1; // divide by 2 for offset
 	cdata->offs_y=(pack.data[1]&0XF0)>>5; // divide by 2 for offset
@@ -894,7 +921,6 @@
 	}
 	ctx->extradata[0] = pack.data[1];
 
-	codec = avcodec_find_decoder(CODEC_ID_VP6A);
 	priv->pack_offset=2;
 	break;
       case FLV_CODECID_H264:
@@ -915,6 +941,8 @@
 
   }
 
+
+
 #ifdef DEBUG
   fprintf(stderr,"video type is %s %d x %d (%d x %d +%d +%d)\n",cdata->video_name,
 	  cdata->width,cdata->height,cdata->frame_width,cdata->frame_height,cdata->offs_x,cdata->offs_y);
@@ -928,7 +956,10 @@
     return FALSE;
   }
 
-  if (avcodec_open(ctx, codec) < 0) {
+  if (ctx==NULL) 
+    priv->ctx = ctx = avcodec_alloc_context3(codec);
+
+  if (avcodec_open2(ctx, codec, NULL) < 0) {
     fprintf(stderr, "flv_decoder: Could not open avcodec context\n");
     detach_stream(cdata);
     return FALSE;
@@ -1309,6 +1340,9 @@
   cdata->asigned=TRUE;
   cdata->ainterleaf=TRUE;
 
+  av_free(priv->picture);
+  priv->picture=NULL;
+
   return cdata;
 }
 
@@ -1451,6 +1485,7 @@
     priv->ctx->skip_frame=AVDISCARD_NONREF;
 
     priv->last_frame=tframe;
+    if (priv->picture==NULL) priv->picture = avcodec_alloc_frame();
 
 
     // do this until we reach target frame //////////////
@@ -1520,7 +1555,7 @@
 
   }
 
-  if (pixel_data==NULL) return TRUE;
+  if (priv->picture==NULL||pixel_data==NULL) return TRUE;
   
   for (p=0;p<nplanes;p++) {
     dst=pixel_data[p];
