--- channels/tsmf/client/ffmpeg/tsmf_ffmpeg.c.orig	2024-04-22 09:26:59 UTC
+++ channels/tsmf/client/ffmpeg/tsmf_ffmpeg.c
@@ -32,6 +32,8 @@
 
 #include <libavcodec/avcodec.h>
 #include <libavutil/common.h>
+#include <libavutil/cpu.h>
+#include <libavutil/imgutils.h>
 
 #include "tsmf_constants.h"
 #include "tsmf_decoder.h"
@@ -125,7 +127,11 @@ static BOOL tsmf_ffmpeg_init_audio_stream(ITSMFDecoder
 	TSMFFFmpegDecoder* mdecoder = (TSMFFFmpegDecoder*)decoder;
 	mdecoder->codec_context->sample_rate = media_type->SamplesPerSecond.Numerator;
 	mdecoder->codec_context->bit_rate = media_type->BitRate;
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+	mdecoder->codec_context->ch_layout.nb_channels = media_type->Channels;
+#else
 	mdecoder->codec_context->channels = media_type->Channels;
+#endif
 	mdecoder->codec_context->block_align = media_type->BlockAlign;
 #if LIBAVCODEC_VERSION_MAJOR < 55
 #ifdef AV_CPU_FLAG_SSE2
@@ -393,9 +399,9 @@ static BOOL tsmf_ffmpeg_decode_video(ITSMFDecoder* dec
 		           mdecoder->frame->linesize[2], mdecoder->frame->linesize[3],
 		           mdecoder->codec_context->pix_fmt, mdecoder->codec_context->width,
 		           mdecoder->codec_context->height);
-		mdecoder->decoded_size =
-		    avpicture_get_size(mdecoder->codec_context->pix_fmt, mdecoder->codec_context->width,
-		                       mdecoder->codec_context->height);
+		mdecoder->decoded_size = av_image_get_buffer_size(mdecoder->codec_context->pix_fmt,
+		                                                  mdecoder->codec_context->width,
+		                                                  mdecoder->codec_context->height, 1);
 		mdecoder->decoded_data = calloc(1, mdecoder->decoded_size);
 
 		if (!mdecoder->decoded_data)
@@ -406,11 +412,12 @@ static BOOL tsmf_ffmpeg_decode_video(ITSMFDecoder* dec
 #else
 		frame = av_frame_alloc();
 #endif
-		avpicture_fill((AVPicture*)frame, mdecoder->decoded_data, mdecoder->codec_context->pix_fmt,
-		               mdecoder->codec_context->width, mdecoder->codec_context->height);
-		av_picture_copy((AVPicture*)frame, (AVPicture*)mdecoder->frame,
-		                mdecoder->codec_context->pix_fmt, mdecoder->codec_context->width,
-		                mdecoder->codec_context->height);
+		av_image_fill_arrays(frame->data, frame->linesize, mdecoder->decoded_data,
+		                     mdecoder->codec_context->pix_fmt, mdecoder->codec_context->width,
+		                     mdecoder->codec_context->height, 1);
+		av_image_copy(frame->data, frame->linesize, (const uint8_t**)mdecoder->frame->data,
+		              mdecoder->frame->linesize, mdecoder->codec_context->pix_fmt,
+		              mdecoder->codec_context->width, mdecoder->codec_context->height);
 		av_free(frame);
 	}
 
@@ -497,11 +504,26 @@ static BOOL tsmf_ffmpeg_decode_audio(ITSMFDecoder* dec
 			av_init_packet(&pkt);
 			pkt.data = (BYTE*)src;
 			pkt.size = src_size;
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(57, 48, 101)
 			len = avcodec_decode_audio4(mdecoder->codec_context, decoded_frame, &got_frame, &pkt);
-
+#else
+			len = avcodec_send_packet(mdecoder->codec_context, &pkt);
+			if (len > 0)
+			{
+				do
+				{
+					len = avcodec_receive_frame(mdecoder->codec_context, decoded_frame);
+				} while (len == AVERROR(EAGAIN));
+			}
+#endif
 			if (len >= 0 && got_frame)
 			{
-				frame_size = av_samples_get_buffer_size(NULL, mdecoder->codec_context->channels,
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+				const int channels = mdecoder->codec_context->ch_layout.nb_channels;
+#else
+				const int channels = mdecoder->codec_context->channels;
+#endif
+				frame_size = av_samples_get_buffer_size(NULL, channels,
 				                                        decoded_frame->nb_samples,
 				                                        mdecoder->codec_context->sample_fmt, 1);
 				memcpy(dst, decoded_frame->data[0], frame_size);
