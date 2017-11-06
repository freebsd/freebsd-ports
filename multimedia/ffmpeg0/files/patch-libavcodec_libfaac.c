--- libavcodec/libfaac.c.orig	2015-03-12 00:05:24 UTC
+++ libavcodec/libfaac.c
@@ -84,7 +84,9 @@ static av_cold int Faac_encode_init(AVCo
     }
     faac_cfg->mpegVersion = MPEG4;
     faac_cfg->useTns = 0;
-    faac_cfg->allowMidside = 1;
+    //Do not set allowMidside for API compatibility with faac,
+    //see https://github.com/knik0/faac/issues/8 for details
+    //faac_cfg->allowMidside = 1;
     faac_cfg->bitRate = avctx->bit_rate / avctx->channels;
     faac_cfg->bandWidth = avctx->cutoff;
     if(avctx->flags & CODEC_FLAG_QSCALE) {
