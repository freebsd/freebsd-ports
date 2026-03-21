--- libavcodec/libsvtav1.c.orig	2025-11-23 02:57:58 UTC
+++ libavcodec/libsvtav1.c
@@ -195,7 +195,11 @@ static int config_enc_params(EbSvtAv1EncConfiguration 
     } else if (svt_enc->qp > 0) {
         param->qp                   = svt_enc->qp;
         param->rate_control_mode    = 0;
+#if SVT_AV1_CHECK_VERSION(4, 0, 1)
+        param->aq_mode = 0;
+#else
         param->enable_adaptive_quantization = 0;
+#endif
     }
 
     desc = av_pix_fmt_desc_get(avctx->pix_fmt);
@@ -389,7 +393,11 @@ static av_cold int eb_enc_init(AVCodecContext *avctx)
 
     svt_enc->eos_flag = EOS_NOT_REACHED;
 
+#if SVT_AV1_CHECK_VERSION(3, 0, 0)
+    svt_ret = svt_av1_enc_init_handle(&svt_enc->svt_handle, &svt_enc->enc_params);
+#else
     svt_ret = svt_av1_enc_init_handle(&svt_enc->svt_handle, svt_enc, &svt_enc->enc_params);
+#endif
     if (svt_ret != EB_ErrorNone) {
         return svt_print_error(avctx, svt_ret, "Error initializing encoder handle");
     }
