--- ../nginx-vod-module-1.23/vod/filters/audio_encoder.c.orig	2018-05-13 10:05:51.704192000 -0400
+++ ../nginx-vod-module-1.23/vod/filters/audio_encoder.c	2018-05-13 10:08:30.590029000 -0400
@@ -100,7 +100,7 @@
 	encoder->channel_layout = params->channel_layout;
 	encoder->channels = params->channels;
 	encoder->bit_rate = params->bitrate;
-	encoder->flags |= CODEC_FLAG_GLOBAL_HEADER;		// make the codec generate the extra data
+	encoder->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;		// make the codec generate the extra data
 
 	avrc = avcodec_open2(encoder, encoder_codec, NULL);
 	if (avrc < 0)
@@ -139,7 +139,7 @@
 {
 	audio_encoder_state_t* state = context;
 
-	if ((state->encoder->codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE) != 0)
+	if ((state->encoder->codec->capabilities & AV_CODEC_CAP_VARIABLE_FRAME_SIZE) != 0)
 	{
 		return 0;
 	}
