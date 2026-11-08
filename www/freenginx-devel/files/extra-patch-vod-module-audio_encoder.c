--- ../nginx-vod-module-26f0687/vod/filters/audio_encoder.c.orig	2026-10-29 10:04:13.799620000 -0400
+++ ../nginx-vod-module-26f0687/vod/filters/audio_encoder.c	2026-10-29 10:07:02.414662000 -0400
@@ -26,13 +26,17 @@
 static bool_t
 audio_encoder_is_format_supported(const AVCodec *codec, enum AVSampleFormat sample_fmt)
 {
-	const enum AVSampleFormat *p;
+	const enum AVSampleFormat *p = NULL;
 
-	for (p = codec->sample_fmts; *p != AV_SAMPLE_FMT_NONE; p++)
-	{
-		if (*p == sample_fmt)
+	avcodec_get_supported_config(NULL, codec, AV_CODEC_CONFIG_SAMPLE_FORMAT, 0, (const void **)&p, NULL);
+	if (p) {
+
+		for (; *p != AV_SAMPLE_FMT_NONE; p++)
 		{
-			return TRUE;
+			if (*p == sample_fmt)
+			{
+				return TRUE;
+			}
 		}
 	}
 
@@ -156,7 +160,7 @@
 		return;
 	}
 	
-	avcodec_close(state->encoder);
+	avcodec_free_context(&state->encoder);
 	av_free(state->encoder);
 }
 
