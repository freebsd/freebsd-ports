--- channels/drdynvc/tsmf/ffmpeg/tsmf_ffmpeg.c.orig	2013-10-25 08:48:35.385869420 -0200
+++ channels/drdynvc/tsmf/ffmpeg/tsmf_ffmpeg.c	2013-10-25 08:54:54.476872888 -0200
@@ -34,12 +34,16 @@
 #define AVMEDIA_TYPE_AUDIO 1
 #endif
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000
+#endif
+
 typedef struct _TSMFFFmpegDecoder
 {
 	ITSMFDecoder iface;
 
 	int media_type;
-	enum CodecID codec_id;
+	enum AVCodecID codec_id;
 	AVCodecContext* codec_context;
 	AVCodec* codec;
 	AVFrame* frame;
@@ -89,13 +93,9 @@
 	mdecoder->codec_context->block_align = media_type->BlockAlign;
 
 #ifdef AV_CPU_FLAG_SSE2
-	mdecoder->codec_context->dsp_mask = AV_CPU_FLAG_SSE2 | AV_CPU_FLAG_MMX2;
+	av_set_cpu_flags_mask(AV_CPU_FLAG_SSE2 | AV_CPU_FLAG_MMX2);
 #else
-#if LIBAVCODEC_VERSION_MAJOR < 53
-	mdecoder->codec_context->dsp_mask = FF_MM_SSE2 | FF_MM_MMXEXT;
-#else
-	mdecoder->codec_context->dsp_mask = FF_MM_SSE2 | FF_MM_MMX2;
-#endif
+	av_set_cpu_flags_mask(FF_MM_SSE2 | FF_MM_MMX2);
 #endif
 
 	return true;
