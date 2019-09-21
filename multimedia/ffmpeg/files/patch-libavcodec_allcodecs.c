https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/dc0806dd2588

--- libavcodec/allcodecs.c.orig	2018-11-05 23:22:25 UTC
+++ libavcodec/allcodecs.c
@@ -679,7 +679,6 @@ extern AVCodec ff_pcm_mulaw_at_encoder;
 extern AVCodec ff_pcm_mulaw_at_decoder;
 extern AVCodec ff_qdmc_at_decoder;
 extern AVCodec ff_qdm2_at_decoder;
-extern AVCodec ff_libaom_av1_decoder;
 extern AVCodec ff_libaom_av1_encoder;
 extern AVCodec ff_libaribb24_decoder;
 extern AVCodec ff_libcelt_decoder;
@@ -738,6 +737,7 @@ extern AVCodec ff_idf_decoder;
 /* external libraries, that shouldn't be used by default if one of the
  * above is available */
 extern AVCodec ff_h263_v4l2m2m_encoder;
+extern AVCodec ff_libaom_av1_decoder;
 extern AVCodec ff_libopenh264_encoder;
 extern AVCodec ff_libopenh264_decoder;
 extern AVCodec ff_h264_amf_encoder;
