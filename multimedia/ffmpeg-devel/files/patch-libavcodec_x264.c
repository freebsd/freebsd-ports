--- libavcodec/x264.c.orig	Mon Feb 20 14:01:29 2006
+++ libavcodec/x264.c	Mon Nov 13 10:29:53 2006
@@ -142,13 +142,17 @@
     x4->params.rc.b_stat_write = (avctx->flags & CODEC_FLAG_PASS1);
     if(avctx->flags & CODEC_FLAG_PASS2) x4->params.rc.b_stat_read = 1;
     else{
-        if(avctx->crf) x4->params.rc.i_rf_constant = avctx->crf;
+#if X264_BUILD >= 54
+        if(avctx->crf) x4->params.rc.f_rf_constant = avctx->crf;
+#else
+	if(avctx->crf) x4->params.rc.i_rf_constant = avctx->crf;
+#endif
         else if(avctx->cqp > -1) x4->params.rc.i_qp_constant = avctx->cqp;
     }
 
     // if neither crf nor cqp modes are selected we have to enable the RC
     // we do it this way because we cannot check if the bitrate has been set
-    if(!(avctx->crf || (avctx->cqp > -1))) x4->params.rc.b_cbr = 1;
+    if(!(avctx->crf || (avctx->cqp > -1))) x4->params.rc.i_rc_method = 1;
 
     x4->params.i_bframe = avctx->max_b_frames;
     x4->params.b_cabac = avctx->coder_type == FF_CODER_TYPE_AC;
