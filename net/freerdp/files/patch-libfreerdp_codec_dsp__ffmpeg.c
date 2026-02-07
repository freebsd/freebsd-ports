--- libfreerdp/codec/dsp_ffmpeg.c.orig	2024-04-22 09:26:59 UTC
+++ libfreerdp/codec/dsp_ffmpeg.c
@@ -225,7 +225,6 @@ static BOOL ffmpeg_open_context(FREERDP_DSP_CONTEXT* c
 static BOOL ffmpeg_open_context(FREERDP_DSP_CONTEXT* context)
 {
 	int ret;
-	int layout;
 	const AUDIO_FORMAT* format;
 
 	if (!context || context->isOpen)
@@ -236,7 +235,6 @@ static BOOL ffmpeg_open_context(FREERDP_DSP_CONTEXT* c
 	if (!format)
 		return FALSE;
 
-	layout = av_get_default_channel_layout(format->nChannels);
 	context->id = ffmpeg_get_avcodec(format);
 
 	if (ffmpeg_codec_is_filtered(context->id, context->encoder))
@@ -263,15 +261,26 @@ static BOOL ffmpeg_open_context(FREERDP_DSP_CONTEXT* c
 			break;
 
 		case AV_CODEC_ID_AAC:
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(60, 31, 102)
 			context->context->profile = FF_PROFILE_AAC_MAIN;
+#elif LIBAVCODEC_VERSION_INT < AV_VERSION_INT(62, 11, 100)
+			context->context->profile = AV_PROFILE_AAC_MAIN;
+#else
+			context->context->profile = AV_PROFILE_AAC_LOW;
+#endif
 			break;
 
 		default:
 			break;
 	}
 
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+	av_channel_layout_default(&context->context->ch_layout, format->nChannels);
+#else
 	context->context->channels = format->nChannels;
+	const int64_t layout = av_get_default_channel_layout(format->nChannels);
 	context->context->channel_layout = layout;
+#endif
 	context->context->sample_rate = format->nSamplesPerSec;
 	context->context->block_align = format->nBlockAlign;
 	context->context->bit_rate = format->nAvgBytesPerSec * 8;
@@ -314,8 +323,12 @@ static BOOL ffmpeg_open_context(FREERDP_DSP_CONTEXT* c
 	if (!context->rcontext)
 		goto fail;
 
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+	av_channel_layout_default(&context->frame->ch_layout, format->nChannels);
+#else
 	context->frame->channel_layout = layout;
 	context->frame->channels = format->nChannels;
+#endif
 	context->frame->sample_rate = format->nSamplesPerSec;
 	context->frame->format = AV_SAMPLE_FMT_S16;
 
@@ -330,13 +343,23 @@ static BOOL ffmpeg_open_context(FREERDP_DSP_CONTEXT* c
 		context->resampled->sample_rate = format->nSamplesPerSec;
 	}
 
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+	av_channel_layout_default(&context->resampled->ch_layout, format->nChannels);
+#else
 	context->resampled->channel_layout = layout;
 	context->resampled->channels = format->nChannels;
+#endif
 
 	if (context->context->frame_size > 0)
 	{
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+		ret = av_channel_layout_copy(&context->buffered->ch_layout, &context->resampled->ch_layout);
+		if (ret != 0)
+			goto fail;
+#else
 		context->buffered->channel_layout = context->resampled->channel_layout;
 		context->buffered->channels = context->resampled->channels;
+#endif
 		context->buffered->format = context->resampled->format;
 		context->buffered->nb_samples = context->context->frame_size;
 
@@ -421,7 +444,12 @@ static BOOL ffmpeg_encode_frame(AVCodecContext* contex
 	if (in->format == AV_SAMPLE_FMT_FLTP)
 	{
 		uint8_t** pp = in->extended_data;
-		for (int y = 0; y < in->channels; y++)
+#if LIBAVUTIL_VERSION_INT < AV_VERSION_INT(57, 28, 100)
+		const int nr_channels = in->channels;
+#else
+		const int nr_channels = in->ch_layout.nb_channels;
+#endif
+		for (int y = 0; y < nr_channels; y++)
 		{
 			float* data = pp[y];
 			for (int x = 0; x < in->nb_samples; x++)
@@ -477,14 +505,21 @@ static BOOL ffmpeg_fill_frame(AVFrame* frame, const AU
                               size_t size)
 {
 	int ret, bpp;
+
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+	av_channel_layout_default(&frame->ch_layout, inputFormat->nChannels);
+#else
 	frame->channels = inputFormat->nChannels;
+	frame->channel_layout = av_get_default_channel_layout(frame->channels);
+#endif
 	frame->sample_rate = inputFormat->nSamplesPerSec;
 	frame->format = ffmpeg_sample_format(inputFormat);
-	frame->channel_layout = av_get_default_channel_layout(frame->channels);
+
 	bpp = av_get_bytes_per_sample(frame->format);
 	frame->nb_samples = size / inputFormat->nChannels / bpp;
 
-	if ((ret = avcodec_fill_audio_frame(frame, frame->channels, frame->format, data, size, 1)) < 0)
+	if ((ret = avcodec_fill_audio_frame(frame, inputFormat->nChannels, frame->format, data, size,
+	                                    1)) < 0)
 	{
 		const char* err = av_err2str(ret);
 		WLog_ERR(TAG, "Error during audio frame fill %s [%d]", err, ret);
@@ -566,8 +601,15 @@ static BOOL ffmpeg_decode(AVCodecContext* dec_ctx, AVP
 		}
 
 		{
-			const size_t data_size = resampled->channels * resampled->nb_samples * 2;
-			Stream_EnsureRemainingCapacity(out, data_size);
+
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+			const size_t nrchannels = resampled->ch_layout.nb_channels;
+#else
+			const size_t nrchannels = resampled->channels;
+#endif
+			const size_t data_size = nrchannels * resampled->nb_samples * 2;
+			if (!Stream_EnsureRemainingCapacity(out, data_size))
+				return FALSE;
 			Stream_Write(out, resampled->data[0], data_size);
 		}
 	}
@@ -661,10 +703,15 @@ BOOL freerdp_dsp_ffmpeg_encode(FREERDP_DSP_CONTEXT* co
 			if (inSamples + (int)context->bufferedSamples > context->context->frame_size)
 				inSamples = context->context->frame_size - (int)context->bufferedSamples;
 
-			rc =
-			    av_samples_copy(context->buffered->extended_data, context->resampled->extended_data,
-			                    (int)context->bufferedSamples, copied, inSamples,
-			                    context->context->channels, context->context->sample_fmt);
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+			const size_t nrchannels = context->context->ch_layout.nb_channels;
+#else
+			const size_t nrchannels = context->context->channels;
+#endif
+
+			rc = av_samples_copy(context->buffered->extended_data,
+			                     context->resampled->extended_data, (int)context->bufferedSamples,
+			                     copied, inSamples, nrchannels, context->context->sample_fmt);
 			rest -= inSamples;
 			copied += inSamples;
 			context->bufferedSamples += (UINT32)inSamples;
