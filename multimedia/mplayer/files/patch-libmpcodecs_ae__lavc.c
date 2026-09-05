--- libmpcodecs/ae_lavc.c.orig	2024-04-14 12:12:16 UTC
+++ libmpcodecs/ae_lavc.c
@@ -177,10 +177,16 @@ int mpae_init_lavc(audio_encoder_t *encoder)
 	lavc_actx->codec_id = lavc_acodec->id;
 	// put sample parameters
 	lavc_actx->sample_fmt = AV_SAMPLE_FMT_S16;
-	if (lavc_acodec->sample_fmts) {
+	const enum AVSampleFormat *sample_fmts;
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 3, 100) // FFmpeg 7.0+
+	avcodec_get_supported_config(lavc_actx, lavc_acodec, AV_CODEC_CONFIG_SAMPLE_FORMAT, 0, (const void **)&sample_fmts, NULL);
+#else
+	sample_fmts = lavc_acodec->sample_fmts;
+#endif
+	if (sample_fmts) {
 		const enum AVSampleFormat *fmts;
-		lavc_actx->sample_fmt = lavc_acodec->sample_fmts[0]; // fallback to first format
-		for (fmts = lavc_acodec->sample_fmts; *fmts != AV_SAMPLE_FMT_NONE; fmts++) {
+		lavc_actx->sample_fmt = sample_fmts[0]; // fallback to first format
+		for (fmts = sample_fmts; *fmts != AV_SAMPLE_FMT_NONE; fmts++) {
 			if (samplefmt2affmt(av_get_packed_sample_fmt(*fmts)) == encoder->params.sample_format) { // preferred format found
 				lavc_actx->sample_fmt = *fmts;
 				break;
