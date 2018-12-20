https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/aaf917157479

--- libavcodec/libaomenc.c.orig	2018-11-05 23:22:26 UTC
+++ libavcodec/libaomenc.c
@@ -192,7 +192,12 @@ static av_cold void free_frame_list(struct FrameListDa
 }
 
 static av_cold int codecctl_int(AVCodecContext *avctx,
-                                enum aome_enc_control_id id, int val)
+#ifdef UENUM1BYTE
+                                aome_enc_control_id id,
+#else
+                                enum aome_enc_control_id id,
+#endif
+                                int val)
 {
     AOMContext *ctx = avctx->priv_data;
     char buf[80];
@@ -288,7 +293,7 @@ static int set_pix_fmt(AVCodecContext *avctx, aom_code
 
 static void set_color_range(AVCodecContext *avctx)
 {
-    enum aom_color_range aom_cr;
+    aom_color_range_t aom_cr;
     switch (avctx->color_range) {
     case AVCOL_RANGE_UNSPECIFIED:
     case AVCOL_RANGE_MPEG:       aom_cr = AOM_CR_STUDIO_RANGE; break;
