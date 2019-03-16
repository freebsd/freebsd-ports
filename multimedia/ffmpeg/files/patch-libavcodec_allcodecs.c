- Prefer libdav1d over libaom decoder for AV1 streams

--- libavcodec/allcodecs.c.orig	2018-11-05 23:22:25 UTC
+++ libavcodec/allcodecs.c
@@ -672,12 +672,12 @@ extern AVCodec ff_pcm_mulaw_at_encoder;
 extern AVCodec ff_pcm_mulaw_at_decoder;
 extern AVCodec ff_qdmc_at_decoder;
 extern AVCodec ff_qdm2_at_decoder;
+extern AVCodec ff_libdav1d_decoder;
 extern AVCodec ff_libaom_av1_decoder;
 extern AVCodec ff_libaom_av1_encoder;
 extern AVCodec ff_libcelt_decoder;
 extern AVCodec ff_libcodec2_encoder;
 extern AVCodec ff_libcodec2_decoder;
-extern AVCodec ff_libdav1d_decoder;
 extern AVCodec ff_libdavs2_decoder;
 extern AVCodec ff_libfdk_aac_encoder;
 extern AVCodec ff_libfdk_aac_decoder;
