--- ./libavcodec/libx264.c.orig	2007-10-07 21:49:37.000000000 +0200
+++ ./libavcodec/libx264.c	2009-04-01 00:07:32.000000000 +0200
@@ -70,6 +70,7 @@
 X264_frame(AVCodecContext *ctx, uint8_t *buf, int bufsize, void *data)
 {
     X264Context *x4 = ctx->priv_data;
+    av_freep(&ctx->extradata);
     AVFrame *frame = data;
     x264_nal_t *nal;
     int nnal, i;
@@ -162,7 +163,7 @@
 
     x4->params.i_bframe = avctx->max_b_frames;
     x4->params.b_cabac = avctx->coder_type == FF_CODER_TYPE_AC;
-    x4->params.b_bframe_adaptive = avctx->b_frame_strategy;
+    x4->params.i_bframe_adaptive = avctx->b_frame_strategy;
     x4->params.i_bframe_bias = avctx->bframebias;
     x4->params.b_bframe_pyramid = (avctx->flags2 & CODEC_FLAG2_BPYRAMID);
     avctx->has_b_frames= (avctx->flags2 & CODEC_FLAG2_BPYRAMID) ? 2 : !!avctx->max_b_frames;
@@ -225,8 +226,6 @@
     x4->params.analyse.i_me_range = avctx->me_range;
     x4->params.analyse.i_subpel_refine = avctx->me_subpel_quality;
 
-    x4->params.analyse.b_bidir_me = (avctx->bidir_refine > 0);
-    x4->params.analyse.b_bframe_rdo = (avctx->flags2 & CODEC_FLAG2_BRDO);
     x4->params.analyse.b_mixed_references =
         (avctx->flags2 & CODEC_FLAG2_MIXED_REFS);
     x4->params.analyse.b_chroma_me = (avctx->me_cmp & FF_CMP_CHROMA);
@@ -251,7 +250,6 @@
     x4->params.rc.f_ip_factor = 1/fabs(avctx->i_quant_factor);
     x4->params.rc.f_pb_factor = avctx->b_quant_factor;
     x4->params.analyse.i_chroma_qp_offset = avctx->chromaoffset;
-    x4->params.rc.psz_rc_eq = avctx->rc_eq;
 
     x4->params.analyse.b_psnr = (avctx->flags & CODEC_FLAG_PSNR);
     x4->params.i_log_level = X264_LOG_DEBUG;
