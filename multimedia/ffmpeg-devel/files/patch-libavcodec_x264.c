--- libavcodec/x264.c.orig	Thu Aug 10 06:10:59 2006
+++ libavcodec/x264.c	Thu Aug 10 06:11:24 2006
@@ -148,7 +148,7 @@
 
     // if neither crf nor cqp modes are selected we have to enable the RC
     // we do it this way because we cannot check if the bitrate has been set
-    if(!(avctx->crf || (avctx->cqp > -1))) x4->params.rc.b_cbr = 1;
+    if(!(avctx->crf || (avctx->cqp > -1))) x4->params.rc.i_rc_method = 1;
 
     x4->params.i_bframe = avctx->max_b_frames;
     x4->params.b_cabac = avctx->coder_type == FF_CODER_TYPE_AC;
