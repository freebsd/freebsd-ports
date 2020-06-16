https://github.com/OpenVisualCloud/SVT-VP9/issues/116

--- libavcodec/libsvt_vp9.c.orig	2020-06-15 18:54:23 UTC
+++ libavcodec/libsvt_vp9.c
@@ -188,9 +188,6 @@ static int config_enc_params(EbSvtVp9EncConfiguration 
         param->min_qp_allowed       = avctx->qmin;
     }
 
-    param->intra_refresh_type       =
-        !!(avctx->flags & AV_CODEC_FLAG_CLOSED_GOP) + 1;
-
     if (ten_bits) {
         param->encoder_bit_depth        = 10;
     }
