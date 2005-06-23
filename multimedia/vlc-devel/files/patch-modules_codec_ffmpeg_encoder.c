--- modules/codec/ffmpeg/encoder.c.orig	Thu Jun 23 05:09:11 2005
+++ modules/codec/ffmpeg/encoder.c	Thu Jun 23 05:10:04 2005
@@ -364,7 +364,9 @@
         p_context->lumi_masking = p_sys->f_lumi_masking;
         p_context->dark_masking = p_sys->f_dark_masking;
         p_context->p_masking = p_sys->f_p_masking;
+#if LIBAVCODEC_BUILD >= 4754
         p_context->border_masking = p_sys->f_border_masking;
+#endif
         p_context->luma_elim_threshold = p_sys->i_luma_elim;
         p_context->chroma_elim_threshold = p_sys->i_chroma_elim;
 
