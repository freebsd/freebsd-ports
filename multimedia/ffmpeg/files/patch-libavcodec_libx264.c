--- ./libavcodec/libx264.c.orig	2008-06-12 23:50:13.000000000 +0200
+++ ./libavcodec/libx264.c	2008-10-13 15:47:05.000000000 +0200
@@ -124,6 +124,8 @@
 {
     X264Context *x4 = avctx->priv_data;
 
+    av_freep(&avctx->extradata);
+
     if(x4->enc)
         x264_encoder_close(x4->enc);
 
@@ -162,7 +164,7 @@
 
     x4->params.i_bframe = avctx->max_b_frames;
     x4->params.b_cabac = avctx->coder_type == FF_CODER_TYPE_AC;
-    x4->params.b_bframe_adaptive = avctx->b_frame_strategy;
+    x4->params.i_bframe_adaptive = avctx->b_frame_strategy;
     x4->params.i_bframe_bias = avctx->bframebias;
     x4->params.b_bframe_pyramid = avctx->flags2 & CODEC_FLAG2_BPYRAMID;
     avctx->has_b_frames= avctx->flags2 & CODEC_FLAG2_BPYRAMID ? 2 : !!avctx->max_b_frames;
@@ -227,8 +229,6 @@
     x4->params.analyse.i_me_range = avctx->me_range;
     x4->params.analyse.i_subpel_refine = avctx->me_subpel_quality;
 
-    x4->params.analyse.b_bidir_me = avctx->bidir_refine > 0;
-    x4->params.analyse.b_bframe_rdo = avctx->flags2 & CODEC_FLAG2_BRDO;
     x4->params.analyse.b_mixed_references =
         avctx->flags2 & CODEC_FLAG2_MIXED_REFS;
     x4->params.analyse.b_chroma_me = avctx->me_cmp & FF_CMP_CHROMA;
@@ -253,7 +253,6 @@
     x4->params.rc.f_ip_factor = 1/fabs(avctx->i_quant_factor);
     x4->params.rc.f_pb_factor = avctx->b_quant_factor;
     x4->params.analyse.i_chroma_qp_offset = avctx->chromaoffset;
-    x4->params.rc.psz_rc_eq = avctx->rc_eq;
 
     x4->params.analyse.b_psnr = avctx->flags & CODEC_FLAG_PSNR;
     x4->params.i_log_level = X264_LOG_DEBUG;
