--- libavcodec/x264.c.orig	Mon Feb 20 16:01:06 2006
+++ libavcodec/x264.c	Mon Oct  2 22:26:03 2006
@@ -148,7 +148,7 @@
 
     // if neither crf nor cqp modes are selected we have to enable the RC
     // we do it this way because we cannot check if the bitrate has been set
-    if(!(avctx->crf || (avctx->cqp > -1))) x4->params.rc.b_cbr = 1;
+    if(!(avctx->crf || (avctx->cqp > -1))) x4->params.rc.i_rc_method = 1;
 
     x4->params.i_bframe = avctx->max_b_frames;
     x4->params.b_cabac = avctx->coder_type == FF_CODER_TYPE_AC;
