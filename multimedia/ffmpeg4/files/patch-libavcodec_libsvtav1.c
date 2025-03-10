https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/d1ed5c06e3ed

--- libavcodec/libsvtav1.c.orig	2024-08-01 23:22:48 UTC
+++ libavcodec/libsvtav1.c
@@ -389,7 +389,11 @@ static av_cold int eb_enc_init(AVCodecContext *avctx)
 
     svt_enc->eos_flag = EOS_NOT_REACHED;
 
+#if SVT_AV1_CHECK_VERSION(3, 0, 0)
+    svt_ret = svt_av1_enc_init_handle(&svt_enc->svt_handle, &svt_enc->enc_params);
+#else
     svt_ret = svt_av1_enc_init_handle(&svt_enc->svt_handle, svt_enc, &svt_enc->enc_params);
+#endif
     if (svt_ret != EB_ErrorNone) {
         return svt_print_error(avctx, svt_ret, "Error initializing encoder handle");
     }
