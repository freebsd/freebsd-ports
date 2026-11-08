--- ../nginx-vod-module-26f0687/vod/filters/audio_decoder.c.orig	2026-10-29 10:03:36.417347000 -0400
+++ ../nginx-vod-module-26f0687/vod/filters/audio_decoder.c	2026-10-29 10:03:59.091542000 -0400
@@ -159,7 +159,7 @@
 void
 audio_decoder_free(audio_decoder_state_t* state)
 {
-	avcodec_close(state->decoder);
+	avcodec_free_context(&state->decoder);
 	av_free(state->decoder);
 	state->decoder = NULL;
 	av_frame_free(&state->decoded_frame);
