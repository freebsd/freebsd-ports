--- ./src/mediatrc_ffmpeg.cpp.orig	2011-05-15 15:23:34.000000000 +0200
+++ ./src/mediatrc_ffmpeg.cpp	2011-10-03 15:08:51.198106365 +0200
@@ -3,7 +3,7 @@
 // Purpose:     FFMPEG Media Transcoder
 // Author:      Alex Thuering
 // Created:     26.04.2008
-// RCS-ID:      $Id: mediatrc_ffmpeg.cpp,v 1.33 2011/05/15 13:23:34 ntalex Exp $
+// RCS-ID:      $Id: mediatrc_ffmpeg.cpp,v 1.36 2011/08/14 11:33:21 ntalex Exp $
 // Copyright:   (c) Alex Thuering
 // Licence:     GPL
 /////////////////////////////////////////////////////////////////////////////
@@ -17,21 +17,16 @@
 #include <math.h>
 #include <errno.h>
 extern "C" {
-#ifdef HAVE_FFMPEG_AVUTIL_H
-#include <opt.h>
-#include <swscale.h>
-#include <avutil.h>
-#include <fifo.h>
-#include <avfilter.h>
-#include <avfiltergraph.h>
-#else
-#include <libavcodec/opt.h>
-#include <libswscale/swscale.h>
+#include <libavutil/opt.h>
 #include <libavutil/avutil.h>
 #include <libavutil/fifo.h>
+#include <libavutil/dict.h>
+#include <libavutil/pixdesc.h>
+#include <libswscale/swscale.h>
+#include <libavfilter/avcodec.h>
 #include <libavfilter/avfilter.h>
 #include <libavfilter/avfiltergraph.h>
-#endif
+#include <libavfilter/vsink_buffer.h>
 }
 
 #define AUDIO_BUF_SIZE 50000
@@ -48,101 +43,19 @@
 #define INT64_MAX INT64_C(9223372036854775807)
 #endif
 
-#if LIBAVFORMAT_VERSION_INT < AV_VERSION_INT(52, 45, 0)
-#define av_guess_format guess_format
-#endif
-
-#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(52, 64, 0)
-#define AVMediaType CodecType
-#define AVMEDIA_TYPE_UNKNOWN CODEC_TYPE_UNKNOWN
-#define AVMEDIA_TYPE_VIDEO CODEC_TYPE_VIDEO
-#define AVMEDIA_TYPE_AUDIO CODEC_TYPE_AUDIO
-#define AVMEDIA_TYPE_DATA CODEC_TYPE_DATA
-#define AVMEDIA_TYPE_SUBTITLE CODEC_TYPE_SUBTITLE
-#define AVMEDIA_TYPE_ATTACHMENT CODEC_TYPE_ATTACHMENT
-#define AVMEDIA_TYPE_NB CODEC_TYPE_NB
+#if LIBAVFORMAT_VERSION_INT < AV_VERSION_INT(53, 4, 0)
+#define AVIO_FLAG_WRITE AVIO_WRONLY
 #endif
 
 //////////////////////////// AVAudioConvert /////////////////////////////////
-
-struct AVAudioConvert {
-    int in_channels, out_channels;
-    int fmt_pair;
-};
-
-AVAudioConvert *av_audio_convert_alloc(enum AVSampleFormat out_fmt, int out_channels,
-                                       enum AVSampleFormat in_fmt, int in_channels,
-                                       const float *matrix, int flags) {
-	AVAudioConvert *ctx;
-	if (in_channels != out_channels)
-		return NULL;
-	ctx = (AVAudioConvert*) av_malloc(sizeof(AVAudioConvert));
-	if (!ctx)
-		return NULL;
-	ctx->in_channels = in_channels;
-	ctx->out_channels = out_channels;
-	ctx->fmt_pair = out_fmt + AV_SAMPLE_FMT_NB * in_fmt;
-	return ctx;
-}
-
-void av_audio_convert_free(AVAudioConvert *ctx) {
-    av_free(ctx);
-}
-
-int av_audio_convert(AVAudioConvert *ctx,
-                     void * const out[6], const int out_stride[6],
-                     const void * const in[6], const int in_stride[6], int len) {
-	int ch;
-
-	//FIXME optimize common cases
-
-	for (ch = 0; ch < ctx->out_channels; ch++) {
-		const int is = in_stride[ch];
-		const int os = out_stride[ch];
-		const uint8_t *pi = (const uint8_t *) in[ch];
-		uint8_t *po = (uint8_t *) out[ch];
-		uint8_t *end = po + os * len;
-		if (!out[ch])
-			continue;
-
-#define CONV(ofmt, otype, ifmt, expr)\
-if(ctx->fmt_pair == ofmt + AV_SAMPLE_FMT_NB*ifmt){\
-    do{\
-        *(otype*)po = expr; pi += is; po += os;\
-    }while(po < end);\
-}
-
-//FIXME put things below under ifdefs so we do not waste space for cases no codec will need
-//FIXME rounding ?
-
-             CONV(AV_SAMPLE_FMT_U8 , uint8_t, AV_SAMPLE_FMT_U8 ,  *(const uint8_t*)pi)
-        else CONV(AV_SAMPLE_FMT_S16, int16_t, AV_SAMPLE_FMT_U8 , (*(const uint8_t*)pi - 0x80)<<8)
-        else CONV(AV_SAMPLE_FMT_S32, int32_t, AV_SAMPLE_FMT_U8 , (*(const uint8_t*)pi - 0x80)<<24)
-        else CONV(AV_SAMPLE_FMT_FLT, float  , AV_SAMPLE_FMT_U8 , (*(const uint8_t*)pi - 0x80)*(1.0 / (1<<7)))
-        else CONV(AV_SAMPLE_FMT_DBL, double , AV_SAMPLE_FMT_U8 , (*(const uint8_t*)pi - 0x80)*(1.0 / (1<<7)))
-        else CONV(AV_SAMPLE_FMT_U8 , uint8_t, AV_SAMPLE_FMT_S16, (*(const int16_t*)pi>>8) + 0x80)
-        else CONV(AV_SAMPLE_FMT_S16, int16_t, AV_SAMPLE_FMT_S16,  *(const int16_t*)pi)
-        else CONV(AV_SAMPLE_FMT_S32, int32_t, AV_SAMPLE_FMT_S16,  *(const int16_t*)pi<<16)
-        else CONV(AV_SAMPLE_FMT_FLT, float  , AV_SAMPLE_FMT_S16,  *(const int16_t*)pi*(1.0 / (1<<15)))
-        else CONV(AV_SAMPLE_FMT_DBL, double , AV_SAMPLE_FMT_S16,  *(const int16_t*)pi*(1.0 / (1<<15)))
-        else CONV(AV_SAMPLE_FMT_U8 , uint8_t, AV_SAMPLE_FMT_S32, (*(const int32_t*)pi>>24) + 0x80)
-        else CONV(AV_SAMPLE_FMT_S16, int16_t, AV_SAMPLE_FMT_S32,  *(const int32_t*)pi>>16)
-        else CONV(AV_SAMPLE_FMT_S32, int32_t, AV_SAMPLE_FMT_S32,  *(const int32_t*)pi)
-        else CONV(AV_SAMPLE_FMT_FLT, float  , AV_SAMPLE_FMT_S32,  *(const int32_t*)pi*(1.0 / (1U<<31)))
-        else CONV(AV_SAMPLE_FMT_DBL, double , AV_SAMPLE_FMT_S32,  *(const int32_t*)pi*(1.0 / (1U<<31)))
-        else CONV(AV_SAMPLE_FMT_U8 , uint8_t, AV_SAMPLE_FMT_FLT, av_clip_uint8(  lrintf(*(const float*)pi * (1<<7)) + 0x80))
-        else CONV(AV_SAMPLE_FMT_S16, int16_t, AV_SAMPLE_FMT_FLT, av_clip_int16(  lrintf(*(const float*)pi * (1<<15))))
-        else CONV(AV_SAMPLE_FMT_S32, int32_t, AV_SAMPLE_FMT_FLT, av_clipl_int32(llrintf(*(const float*)pi * (1U<<31))))
-        else CONV(AV_SAMPLE_FMT_FLT, float  , AV_SAMPLE_FMT_FLT, *(const float*)pi)
-        else CONV(AV_SAMPLE_FMT_DBL, double , AV_SAMPLE_FMT_FLT, *(const float*)pi)
-        else CONV(AV_SAMPLE_FMT_U8 , uint8_t, AV_SAMPLE_FMT_DBL, av_clip_uint8(  lrint(*(const double*)pi * (1<<7)) + 0x80))
-        else CONV(AV_SAMPLE_FMT_S16, int16_t, AV_SAMPLE_FMT_DBL, av_clip_int16(  lrint(*(const double*)pi * (1<<15))))
-        else CONV(AV_SAMPLE_FMT_S32, int32_t, AV_SAMPLE_FMT_DBL, av_clipl_int32(llrint(*(const double*)pi * (1U<<31))))
-        else CONV(AV_SAMPLE_FMT_FLT, float  , AV_SAMPLE_FMT_DBL, *(const double*)pi)
-        else CONV(AV_SAMPLE_FMT_DBL, double , AV_SAMPLE_FMT_DBL, *(const double*)pi)
-        else return -1;
-    }
-    return 0;
+// audioconvert.h
+extern "C" {
+struct AVAudioConvert;
+AVAudioConvert *av_audio_convert_alloc(enum AVSampleFormat out_fmt, int out_channels, enum AVSampleFormat in_fmt,
+		int in_channels, const float *matrix, int flags);
+void av_audio_convert_free(AVAudioConvert *ctx);
+int av_audio_convert(AVAudioConvert *ctx, void * const out[6], const int out_stride[6], const void * const in[6],
+		const int in_stride[6], int len);
 }
 
 //////////////////////////// AVOutputStream /////////////////////////////////
@@ -161,6 +74,8 @@
 	struct AVInputStream *sync_ist; /* input stream to sync against */
 	int64_t sync_opts; /* output frame counter, could be changed to some true timestamp *///FIXME look at frame_number
 	AVBitStreamFilterContext *bitstream_filters;
+	AVCodec *enc;
+	
 	/* video only */
 	int video_resample;
 	AVFrame resample_frame; /* temporary frame for image resampling */
@@ -168,17 +83,19 @@
 	int resample_height;
 	int resample_width;
 	int resample_pix_fmt;
+    AVRational frame_rate;
 	
 	float frame_aspect_ratio;
+	
 	/* forced key frames */
-//	int64_t *forced_kf_pts;
-//	int forced_kf_count;
-//	int forced_kf_index;
+	int64_t *forced_kf_pts;
+	int forced_kf_count;
+	int forced_kf_index;
 
 	/* audio only */
 	int audio_resample;
 	ReSampleContext *resample; /* for audio resampling */
-	int resample_sample_fmt;
+	AVSampleFormat resample_sample_fmt;
 	int resample_channels;
 	int resample_sample_rate;
 	int reformat_pair;
@@ -216,94 +133,23 @@
 } AVInputStream;
 
 typedef struct AVInputFile {
+	AVFormatContext *ctx;
 	int eof_reached; /* true if eof reached */
 	int ist_index; /* index of first stream in ist_table */
 	int buffer_size; /* current total buffer size */
-	int nb_streams; /* nb streams we are aware of */
+	int nb_streams;
 } AVInputFile;
 
-//#include <libavfilter/vsrc_buffer.h>
-extern "C" {
-	int av_vsrc_buffer_add_frame2(AVFilterContext *buffer_filter, AVFrame *frame, int64_t pts,
-			AVRational pixel_aspect, int width, int height, enum PixelFormat pix_fmt, const char *sws_param);
-}
-
-//#include "cmdutils.h"
-typedef struct {
-    enum PixelFormat pix_fmt;
-} FFSinkContext;
-
-int ffsink_init(AVFilterContext *ctx, const char *args, void *opaque)
+static int configure_video_filters(AVInputStream *ist, AVOutputStream *ost)
 {
-    FFSinkContext *priv = (FFSinkContext*) ctx->priv;
-
-    if (!opaque)
-        return AVERROR(EINVAL);
-    *priv = *(FFSinkContext *)opaque;
-
-    return 0;
-}
-
-void null_end_frame(AVFilterLink *inlink) { }
-
-int ffsink_query_formats(AVFilterContext *ctx) {
-    FFSinkContext *priv = (FFSinkContext*) ctx->priv;
-    int pix_fmts[] = { priv->pix_fmt, PIX_FMT_NONE };
-
-    avfilter_set_common_formats(ctx, avfilter_make_format_list(pix_fmts));
-    return 0;
-}
-
-int get_filtered_video_frame(AVFilterContext *ctx, AVFrame *frame, AVFilterBufferRef **picref_ptr, AVRational *tb) {
-	int ret;
-	AVFilterBufferRef *picref;
-	
-	if ((ret = avfilter_request_frame(ctx->inputs[0])) < 0)
-		return ret;
-	if (!(picref = ctx->inputs[0]->cur_buf))
-		return AVERROR(ENOENT);
-	*picref_ptr = picref;
-	ctx->inputs[0]->cur_buf = NULL;
-	*tb = ctx->inputs[0]->time_base;
-	
-	memcpy(frame->data, picref->data, sizeof(frame->data));
-	memcpy(frame->linesize, picref->linesize, sizeof(frame->linesize));
-	frame->interlaced_frame = picref->video->interlaced;
-	frame->top_field_first = picref->video->top_field_first;
-	
-	return 1;
-}
-
-AVFilter ffsink;
-AVFilterPad fInputs[2];
-AVFilterPad fOutputs[1];
-
-int configure_filters(AVInputStream *ist, AVOutputStream *ost) {
     AVFilterContext *last_filter, *filter;
     /** filter graph containing all filters including input & output */
     AVCodecContext *codec = ost->st->codec;
     AVCodecContext *icodec = ist->st->codec;
-    FFSinkContext ffsink_ctx;
-    ffsink_ctx.pix_fmt = codec->pix_fmt;
+    enum PixelFormat pix_fmts[] = { codec->pix_fmt, PIX_FMT_NONE };
     AVRational sample_aspect_ratio;
     char args[255];
     int ret;
-    
-	ffsink.name = "ffsink";
-	ffsink.priv_size = sizeof(FFSinkContext);
-	ffsink.init = ffsink_init;
-	ffsink.query_formats = ffsink_query_formats;
-	
-	fInputs[0].name = "default";
-	fInputs[0].type = AVMEDIA_TYPE_VIDEO;
-	fInputs[0].end_frame = null_end_frame;
-	fInputs[0].min_perms = AV_PERM_READ;
-	fInputs[1].name = NULL;
-	ffsink.inputs = fInputs;
-	fOutputs[0].name = NULL;
-	ffsink.outputs = fOutputs;
-	
-	int sws_flags = SWS_BICUBIC;
 
     ost->graph = avfilter_graph_alloc();
 
@@ -320,8 +166,8 @@
                                        "src", args, NULL, ost->graph);
     if (ret < 0)
         return ret;
-    ret = avfilter_graph_create_filter(&ost->output_video_filter, &ffsink,
-                                       "out", NULL, &ffsink_ctx, ost->graph);
+    ret = avfilter_graph_create_filter(&ost->output_video_filter, avfilter_get_by_name("buffersink"),
+                                       "out", NULL, pix_fmts, ost->graph);
     if (ret < 0)
         return ret;
     last_filter = ost->input_video_filter;
@@ -330,7 +176,7 @@
         snprintf(args, 255, "%d:%d:flags=0x%X",
                  codec->width,
                  codec->height,
-                 sws_flags);
+                 ost->sws_flags);
         if ((ret = avfilter_graph_create_filter(&filter, avfilter_get_by_name("scale"),
                                                 NULL, args, NULL, ost->graph)) < 0)
             return ret;
@@ -339,12 +185,12 @@
         last_filter = filter;
     }
 
-    snprintf(args, sizeof(args), "flags=0x%X", sws_flags);
+    snprintf(args, sizeof(args), "flags=0x%X", ost->sws_flags);
     ost->graph->scale_sws_opts = av_strdup(args);
 
     if (ost->avfilter) {
-        AVFilterInOut* outputs = (AVFilterInOut*) av_malloc(sizeof(AVFilterInOut));
-        AVFilterInOut* inputs  = (AVFilterInOut*) av_malloc(sizeof(AVFilterInOut));
+        AVFilterInOut *outputs = avfilter_inout_alloc();
+        AVFilterInOut *inputs  = avfilter_inout_alloc();
 
         outputs->name    = av_strdup("in");
         outputs->filter_ctx = last_filter;
@@ -356,7 +202,7 @@
         inputs->pad_idx = 0;
         inputs->next    = NULL;
 
-        if ((ret = avfilter_graph_parse(ost->graph, ost->avfilter, inputs, outputs, NULL)) < 0)
+        if ((ret = avfilter_graph_parse(ost->graph, ost->avfilter, &inputs, &outputs, NULL)) < 0)
             return ret;
         av_freep(&ost->avfilter);
     } else {
@@ -370,8 +216,10 @@
     codec->width  = ost->output_video_filter->inputs[0]->w;
     codec->height = ost->output_video_filter->inputs[0]->h;
     codec->sample_aspect_ratio = ost->st->sample_aspect_ratio =
+        ost->frame_aspect_ratio ? // overriden by the -aspect cli option
+        av_d2q(ost->frame_aspect_ratio*codec->height/codec->width, 255) :
         ost->output_video_filter->inputs[0]->sample_aspect_ratio;
-    
+
     return 0;
 }
 
@@ -412,12 +260,11 @@
 }
 
 wxFfmpegMediaTranscoder::wxFfmpegMediaTranscoder(int threadCount) {
-	nb_input_files = 0;
 	input_files_ts_scale[0] = NULL;
 	nb_input_files_ts_scale[0] = 0;
-	output_codecs = NULL;
+	input_codecs = NULL;
+	nb_input_codecs = 0;  
 	nb_output_files = 0;
-	nb_output_codecs = 0;
 	stream_maps = NULL;
 	nb_stream_maps = 0;
 	nb_meta_data_maps = 0;
@@ -429,7 +276,6 @@
 	frame_width = 0;
 	frame_height = 0;
 	frame_aspect_ratio = 0;
-	frame_aspect_ratio_override = 0;
 	frame_pix_fmt = PIX_FMT_NONE;
 	frame_bits_per_raw_sample = 0;
 	audio_sample_fmt = SAMPLE_FMT_NONE;
@@ -476,12 +322,12 @@
 	do_psnr = 0;
 	do_pass = 0;
 	pass_logfilename_prefix = "ffmpeg2pass";
-	video_sync_method= -1;
-	audio_sync_method= 0;
-	audio_drift_threshold= 0.1;
-	copy_ts= 0;
-	opt_shortest = 0; //
-	video_global_header = 0;
+	video_sync_method = -1;
+	audio_sync_method = 0;
+	audio_drift_threshold = 0.1;
+	copy_ts = 0;
+	copy_tb = 0;
+	opt_shortest = 0;
 	vstats_filename = NULL;
 	vstats_file = NULL;
 	opt_programid = 0;
@@ -492,8 +338,6 @@
 	video_channel = 0;
 	video_standard = NULL;
 	
-	audio_volume = 256;
-	
 	exit_on_error = 0;
 	verbose = 1;
 	thread_count = threadCount;
@@ -519,6 +363,11 @@
 	audio_bitstream_filters = NULL;
 	subtitle_bitstream_filters = NULL;
 	
+	input_streams = NULL;
+	nb_input_streams = 0;
+	input_files = NULL;
+	nb_input_files = 0;
+	
 	av_log_set_callback(&av_log_wxLog_callback);
 }
 
@@ -531,20 +380,39 @@
 	avfilter_register_all();
 }
 
+// similar to ff_dynarray_add() and av_fast_realloc()
+void* grow_array(void *array, int elem_size, int *size, int new_size) {
+    if (new_size >= INT_MAX / elem_size) {
+        wxLogError(wxT("Array too big."));
+        return NULL;
+    }
+    if (*size < new_size) {
+        uint8_t* tmp = (uint8_t*) av_realloc(array, new_size*elem_size);
+        if (!tmp) {
+        	wxLogError(wxT("Could not alloc buffer."));
+            return NULL;
+        }
+        memset(tmp + *size*elem_size, 0, (new_size-*size) * elem_size);
+        *size = new_size;
+        return tmp;
+    }
+    return array;
+}
+
 bool wxFfmpegMediaTranscoder::AddInputFile(const wxString& fileName, bool disableVideo, bool disableAudio,
 		bool disableSubtitle) {
 	AVFormatContext *ic;
 	int err, i, ret, rfps, rfps_base;
 	int64_t timestamp;
-
+	
 	/* get default parameters from command line */
 	ic = avformat_alloc_context();
 	if (!ic) {
 		PrintError(fileName, AVERROR(ENOMEM));
 		return false;
 	}
-	ic->flags |= AVFMT_FLAG_NONBLOCK;
-
+	ic->flags |= AVFMT_FLAG_NONBLOCK | AVFMT_FLAG_PRIV_OPT;
+	
 	// open the input file with generic libav function
 	err = av_open_input_file(&ic, (const char*) fileName.mb_str(), NULL, 0, NULL);
 	if (err < 0) {
@@ -606,39 +474,38 @@
 	for (i=0; i<(int)ic->nb_streams; i++) {
 		AVStream *st = ic->streams[i];
 		AVCodecContext *dec = st->codec;
+		AVInputStream *ist;
+		
 		dec->thread_count = thread_count;
+        input_codecs = (AVCodec**) grow_array(input_codecs, sizeof(*input_codecs), &nb_input_codecs, nb_input_codecs + 1);
+
+        input_streams = (AVInputStream*) grow_array(input_streams, sizeof(*input_streams), &nb_input_streams, nb_input_streams + 1);
+        ist = &input_streams[nb_input_streams - 1];
+        ist->st = st;
+        ist->file_index = nb_input_files;
+        ist->discard = 1;
+        
 		switch (dec->codec_type) {
 		case AVMEDIA_TYPE_AUDIO:
+			input_codecs[nb_input_codecs-1] = avcodec_find_decoder(dec->codec_id);
 			channel_layout = dec->channel_layout;
-			audio_channels = dec->channels;
-			audio_sample_rate = dec->sample_rate;
 			audio_sample_fmt = dec->sample_fmt;
 			if (disableAudio)
 				st->discard = AVDISCARD_ALL;
-            /* Note that av_find_stream_info can add more streams, and we
-             * currently have no chance of setting up lowres decoding
-             * early enough for them. */
-            if (dec->lowres)
-                audio_sample_rate >>= dec->lowres;
 			break;
 		case AVMEDIA_TYPE_VIDEO:
-			frame_height = dec->height;
-			frame_width = dec->width;
+			input_codecs[nb_input_codecs-1] = avcodec_find_decoder(dec->codec_id);
 			if(st->sample_aspect_ratio.num)
 				frame_aspect_ratio=av_q2d(st->sample_aspect_ratio);
 			else
 				frame_aspect_ratio=av_q2d(dec->sample_aspect_ratio);
 			frame_aspect_ratio *= (float) dec->width / dec->height;
-			frame_aspect_ratio_override = 0;
-			frame_pix_fmt = dec->pix_fmt;
 			rfps = st->r_frame_rate.num;
 			rfps_base = st->r_frame_rate.den;
-			if(dec->lowres) {
+			if (dec->lowres) {
 				dec->flags |= CODEC_FLAG_EMU_EDGE;
-				frame_height >>= dec->lowres;
-				frame_width  >>= dec->lowres;
-				dec->height = frame_height;
-                dec->width  = frame_width;  
+				dec->height >>= dec->lowres;
+				dec->width  >>= dec->lowres;
 			}
 			if (me_threshold)
 				dec->debug |= FF_DEBUG_MV;
@@ -650,9 +517,6 @@
 					i, (float)dec->time_base.den / dec->time_base.num, dec->time_base.den, dec->time_base.num,
 					(float)rfps / rfps_base, rfps, rfps_base);
 			}
-			/* update the current frame rate to match the stream frame rate */
-			frame_rate.num = rfps;
-			frame_rate.den = rfps_base;
 
 			if (disableVideo)
 				st->discard = AVDISCARD_ALL;
@@ -660,6 +524,7 @@
 		case AVMEDIA_TYPE_DATA:
 			break;
 		case AVMEDIA_TYPE_SUBTITLE:
+			input_codecs[nb_input_codecs-1] = avcodec_find_decoder(dec->codec_id);
 			if (disableSubtitle)
 				st->discard = AVDISCARD_ALL;
 			break;
@@ -672,17 +537,27 @@
 		}
 	}
 
-	input_files[nb_input_files] = ic;
 	input_files_ts_offset[nb_input_files] = input_ts_offset - (copy_ts ? 0 : timestamp);
 	/* dump the file content */
 	if (verbose >= 0)
 		av_dump_format(ic, nb_input_files, (const char*)fileName.mb_str(), 0);
 
-	nb_input_files++;
+	input_files = (AVInputFile*) grow_array(input_files, sizeof(*input_files), &nb_input_files, nb_input_files + 1);
+	input_files[nb_input_files - 1].ctx        = ic;
+	input_files[nb_input_files - 1].ist_index  = nb_input_streams - ic->nb_streams;
+	input_files[nb_input_files - 1].nb_streams = ic->nb_streams;
+	
 	input_files_ts_scale[nb_input_files] = NULL;
 	nb_input_files_ts_scale[nb_input_files] = 0;
-
+	
+	top_field_first = -1;
 	video_channel = 0;
+    frame_rate    = (AVRational){0, 0};
+    frame_pix_fmt = PIX_FMT_NONE;
+    frame_height = 0;
+    frame_width  = 0;
+    audio_sample_rate = 0;
+    audio_channels    = 0;
 	return true;
 }
 
@@ -742,27 +617,27 @@
 	
 	oc->timestamp = recording_timestamp;
 	
-	av_metadata_copy(&oc->metadata, metadata, 0);
-	av_metadata_free(&metadata);
-
+	av_dict_copy(&oc->metadata, metadata, 0);
+	av_dict_free(&metadata);
+	
 	output_files[nb_output_files++] = oc;
 
 	/* check filename in case of an image number is expected */
 	if (oc->oformat->flags & AVFMT_NEEDNUMBER) {
 		if (!av_filename_number_test(oc->filename)) {
-			PrintError(fileName, AVERROR_NUMEXPECTED);
+			PrintError(fileName, AVERROR(EINVAL));
 			return false;
 		}
 	}
 
 	/* test if it already exists to avoid loosing precious files */
-	if (url_exist((const char*) fileName.mb_str())) {
+	if (avio_check((const char*) fileName.mb_str(), 0) == 0) {
 		wxLogError(wxT("File '%s' already exists"), fileName.c_str());
 		return false;
 	}
 
 	/* open the file */
-	int err = avio_open(&oc->pb, (const char*) fileName.mb_str(), URL_WRONLY);
+	int err = avio_open(&oc->pb, (const char*) fileName.mb_str(), AVIO_FLAG_WRITE);
 	if (err < 0) {
 		PrintError(fileName, err);
 		return false;
@@ -777,39 +652,24 @@
 	oc->preload= (int)(mux_preload*AV_TIME_BASE);
 	oc->max_delay= (int)(mux_max_delay*AV_TIME_BASE);
 	oc->loop_output = loop_output;
-	oc->flags |= AVFMT_FLAG_NONBLOCK;
-
+	
+	frame_rate    = (AVRational){0, 0};
+	frame_width   = 0;
+	frame_height  = 0;
+	audio_sample_rate = 0;
+	audio_channels    = 0;
+	
 	return true;
 }
 
 void wxFfmpegMediaTranscoder::PrintError(const wxString& msg, int err) {
-	switch (err) {
-	case AVERROR_NUMEXPECTED:
-		wxLogError(wxT("%s: Incorrect image filename syntax.\n"
-				"Use '%%d' to specify the image number:\n"
-				"  for img1.jpg, img2.jpg, ..., use 'img%%d.jpg';\n"
-				"  for img001.jpg, img002.jpg, ..., use 'img%%03d.jpg'."), msg.c_str());
-		break;
-	case AVERROR_INVALIDDATA:
-		wxLogError(wxT("%s: Error while parsing header"), msg.c_str());
-		break;
-	case AVERROR_NOFMT:
-		wxLogError(wxT("%s: Unknown format"), msg.c_str());
-		break;
-	case AVERROR(EIO):
-		wxLogError(wxT("%s: I/O error occured\n"
-				"Usually that means that input file is truncated and/or corrupted."), msg.c_str());
-		break;
-	case AVERROR(ENOMEM):
-		wxLogError(wxT("%s: memory allocation error occured"), msg.c_str());
-		break;
-	case AVERROR(ENOENT):
-		wxLogError(wxT("%s: no such file or directory"), msg.c_str());
-		break;
-	default:
-		wxLogError(wxT("%s: Error while opening file"), msg.c_str());
-		break;
-	}
+	char errbuf[128];
+	const char *errbuf_ptr = errbuf;
+	
+	if (av_strerror(err, errbuf, sizeof(errbuf)) < 0)
+		errbuf_ptr = strerror(AVUNERROR(err));
+	wxString errorStr(errbuf_ptr, wxConvUTF8);
+	wxLogError(msg + wxT(": ") + errorStr);
 }
 
 void choose_pixel_fmt(AVStream *st, AVCodec *codec) {
@@ -819,12 +679,15 @@
 			if(*p == st->codec->pix_fmt)
 				break;
 		}
-		if(*p == -1
-		   && !(   st->codec->codec_id==CODEC_ID_MJPEG
-				&& st->codec->strict_std_compliance <= FF_COMPLIANCE_INOFFICIAL
-				&& (   st->codec->pix_fmt == PIX_FMT_YUV420P
-					|| st->codec->pix_fmt == PIX_FMT_YUV422P)))
+		if (*p == -1) {
+			if(st->codec->pix_fmt != PIX_FMT_NONE)
+			av_log(NULL, AV_LOG_WARNING,
+				   "Incompatible pixel format '%s' for codec '%s', auto-selecting format '%s'\n",
+				   av_pix_fmt_descriptors[st->codec->pix_fmt].name,
+				   codec->name,
+				   av_pix_fmt_descriptors[codec->pix_fmts[0]].name);
 			st->codec->pix_fmt = codec->pix_fmts[0];
+		}
 	}
 }
 
@@ -835,30 +698,20 @@
 			if(*p == st->codec->sample_fmt)
 				break;
 		}
-		if (*p == -1)
+		if (*p == -1) {
+			if ((codec->capabilities & CODEC_CAP_LOSSLESS)
+					&& av_get_sample_fmt_name(st->codec->sample_fmt) > av_get_sample_fmt_name(codec->sample_fmts[0]))
+				av_log(NULL, AV_LOG_ERROR, "Convertion will not be lossless'\n");
+			av_log(NULL, AV_LOG_WARNING,
+				   "Incompatible sample format '%s' for codec '%s', auto-selecting format '%s'\n",
+				   av_get_sample_fmt_name(st->codec->sample_fmt),
+				   codec->name,
+				   av_get_sample_fmt_name(codec->sample_fmts[0]));
 			st->codec->sample_fmt = codec->sample_fmts[0];
+		}
 	}
 }
 
-// similar to ff_dynarray_add() and av_fast_realloc()
-void* grow_array(void *array, int elem_size, int *size, int new_size) {
-    if (new_size >= INT_MAX / elem_size) {
-        wxLogError(wxT("Array too big."));
-        return NULL;
-    }
-    if (*size < new_size) {
-        uint8_t* tmp = (uint8_t*) av_realloc(array, new_size*elem_size);
-        if (!tmp) {
-        	wxLogError(wxT("Could not alloc buffer."));
-            return NULL;
-        }
-        memset(tmp + *size*elem_size, 0, (new_size-*size) * elem_size);
-        *size = new_size;
-        return tmp;
-    }
-    return array;
-}
-
 void choose_sample_rate(AVStream *st, AVCodec *codec) {
 	if (codec && codec->supported_samplerates){
 		const int *p= codec->supported_samplerates;
@@ -893,6 +746,8 @@
 	}
 	ost->file_index = fileIdx;
 	ost->index = idx;
+	
+	ost->sws_flags = SWS_BICUBIC;
 	return ost;
 }
 
@@ -913,8 +768,6 @@
 	if (!ost)
 		return false;  
 	
-	output_codecs = (AVCodec**)
-			grow_array(output_codecs, sizeof(*output_codecs), &nb_output_codecs, nb_output_codecs + 1);
 	if (videoFormat != vfCOPY) {
 		wxSize frameSize = GetFrameSize(videoFormat);
 		frame_width = frameSize.GetWidth();
@@ -929,21 +782,13 @@
 			frame_rate.den = 1001;
 		}
 		codec = avcodec_find_encoder(codecId);
-		output_codecs[nb_output_codecs-1] = codec;
+		ost->enc = codec;
 		
 		char* vfilters = NULL;
 		if (m_videoFilters.length()) {
 			vfilters = (char*) av_realloc(vfilters, m_videoFilters.length() + 1);
 			snprintf(vfilters, m_videoFilters.length() + 1, "%s", (const char*) m_videoFilters.mb_str());
 		}
-        if (frame_aspect_ratio_override) {
-			int i = vfilters ? strlen(vfilters) : 0;
-			vfilters = (char*) av_realloc(vfilters, i + 100);
-			snprintf(vfilters + i, 100, "%csetdar=%f", i ? ',' : ' ', frame_aspect_ratio);
-			frame_aspect_ratio = 0;
-			frame_aspect_ratio_override = 0;
-        }
-
         ost->avfilter = vfilters;
 	}
 	
@@ -954,17 +799,14 @@
 	st->codec->thread_count = thread_count;
 
 	video_enc = st->codec;
-
+	
 	if (video_codec_tag)
 		video_enc->codec_tag= video_codec_tag;
-
-	if ((video_global_header&1) || (video_global_header==0 && (oc->oformat->flags & AVFMT_GLOBALHEADER))) {
+	
+	if (oc->oformat->flags & AVFMT_GLOBALHEADER) {
 		video_enc->flags |= CODEC_FLAG_GLOBAL_HEADER;
 	}
-	if (video_global_header&2) {
-		video_enc->flags2 |= CODEC_FLAG2_LOCAL_HEADER;
-	}
-
+	
 	if (videoFormat == vfCOPY) {
 		st->stream_copy = 1;
 		video_enc->codec_type = AVMEDIA_TYPE_VIDEO;
@@ -974,8 +816,6 @@
 		const char *p;
 		int i;
 		
-		AVRational fps= frame_rate.num ? frame_rate : (AVRational) {25,1};
-		
 		av_set_int(video_enc, "gop", isNTSC(videoFormat) ? 15 : 12);
 		av_set_int(video_enc, "b", bitrate * 1000);
 		av_set_int(video_enc, "maxrate", vbr ? 9000000 : bitrate * 1000);
@@ -985,20 +825,16 @@
 		av_set_int(video_enc, "packetsize", 2048);
 		av_set_int(video_enc, "muxrate", 10080000);
 		
+		if (frame_rate.num)
+			ost->frame_rate = frame_rate;
 		video_enc->codec_id = codecId;
 		
-		if (codec && codec->supported_framerates && !force_fps)
-			fps = codec->supported_framerates[av_find_nearest_q_idx(fps, codec->supported_framerates)];
-		video_enc->time_base.den = fps.num;
-		video_enc->time_base.num = fps.den;
 		video_enc->width = frame_width;
 		video_enc->height = frame_height;
 		video_enc->sample_aspect_ratio = av_d2q(frame_aspect_ratio*frame_height/frame_width, 255);
 		video_enc->pix_fmt = frame_pix_fmt;
 		st->sample_aspect_ratio = video_enc->sample_aspect_ratio; 
-
-		choose_pixel_fmt(st, codec);
-
+		
 		if (intra_only)
 			video_enc->gop_size = 0;
 		if (video_qscale || same_quality) {
@@ -1059,7 +895,7 @@
 //			parse_forced_key_frames(forced_key_frames, ost, video_enc);
 	}
 	if (video_language) {
-		av_metadata_set2(&st->metadata, "language", video_language, 0);
+		av_dict_set(&st->metadata, "language", video_language, 0);
 		av_freep(&video_language);
 	}
 	
@@ -1084,12 +920,10 @@
 	if (!ost)
 		return false;
 	
-	output_codecs = (AVCodec**)
-			grow_array(output_codecs, sizeof(*output_codecs), &nb_output_codecs, nb_output_codecs + 1);
 	if (audioFormat != afNONE && audioFormat != afCOPY) {
 		codecId = audioFormat == afMP2 ? CODEC_ID_MP2 : CODEC_ID_AC3;
 		codec = avcodec_find_encoder(codecId);
-		output_codecs[nb_output_codecs-1] = codec;
+		ost->enc = codec;
 	}
 	
 	audio_sample_rate = 48000;
@@ -1110,8 +944,6 @@
 	}
 	if (audioFormat == afCOPY) {
 		st->stream_copy = 1;
-		audio_enc->channels = audio_channels;
-		audio_enc->sample_rate = audio_sample_rate;
 	} else {
 		av_set_int(audio_enc, "ab", bitrate*1000);
 		codec = avcodec_find_encoder(codecId);
@@ -1122,19 +954,16 @@
 			st->quality = FF_QP2LAMBDA * audio_qscale;
 			audio_enc->global_quality = (int) st->quality;
 		}
-		audio_enc->channels = audio_channels;
+        if (audio_channels)
+            audio_enc->channels = audio_channels;
 		audio_enc->sample_fmt = audio_sample_fmt;
-		audio_enc->sample_rate = audio_sample_rate;
+		if (audio_sample_rate)
+			audio_enc->sample_rate = audio_sample_rate;
 		audio_enc->channel_layout = channel_layout;
-		if (av_get_channel_layout_nb_channels(channel_layout) != audio_channels)
-			audio_enc->channel_layout = 0;
 		choose_sample_fmt(st, codec);
-		choose_sample_rate(st, codec);
 	}
-	audio_enc->sample_rate = audio_sample_rate;
-	audio_enc->time_base= (AVRational) {1, audio_sample_rate};
 	if (audio_language) {
-		av_metadata_set2(&st->metadata, "language", audio_language, 0);
+		av_dict_set(&st->metadata, "language", audio_language, 0);
 		av_freep(&audio_language);
 	}
 	
@@ -1158,11 +987,10 @@
 		return false;
 	subtitle_enc = st->codec;
 	
-	output_codecs = (AVCodec**)
-			grow_array(output_codecs, sizeof(*output_codecs), &nb_output_codecs, nb_output_codecs + 1); 
 	if (subtitleFormat != sfNONE) {
 		codecId = CODEC_ID_DVD_SUBTITLE;
-		codec = output_codecs[nb_output_codecs-1] = avcodec_find_encoder(codecId);
+		codec = avcodec_find_encoder(codecId);
+		ost->enc = codec;
 	}
 	avcodec_get_context_defaults3(st->codec, codec);
 
@@ -1181,7 +1009,7 @@
 	}
 	
 	if (subtitle_language) {
-		av_metadata_set2(&st->metadata, "language", subtitle_language, 0);
+		av_dict_set(&st->metadata, "language", subtitle_language, 0);
 		av_freep(&subtitle_language);
 	}
 	
@@ -1233,7 +1061,7 @@
 }
 
 int wxFfmpegMediaTranscoder::CopyChapters(int infile, int outfile) {
-    AVFormatContext *is = input_files[infile];
+    AVFormatContext *is = input_files[infile].ctx;
     AVFormatContext *os = output_files[outfile];
 
     for (unsigned int i = 0; i < is->nb_chapters; i++) {
@@ -1259,7 +1087,7 @@
         out_ch->end       = FFMIN(rt, in_ch->end   - ts_off);
 
         if (metadata_chapters_autocopy)
-            av_metadata_copy(&out_ch->metadata, in_ch->metadata, 0);
+        	av_dict_copy(&out_ch->metadata, in_ch->metadata, 0);
 
         os->nb_chapters++;
         os->chapters = (AVChapter**) av_realloc(os->chapters, sizeof(AVChapter)*os->nb_chapters);
@@ -1272,11 +1100,11 @@
 
 /** Starts transcoding. */
 bool wxFfmpegMediaTranscoder::Run(bool& canceled) {
-	int ret = 0, i, j, k, n, nb_istreams = 0, nb_ostreams = 0, step;
+	int ret = 0, i, j, k, n, nb_ostreams = 0, step;
 	AVFormatContext *is, *os;
 	AVCodecContext *codec, *icodec;
 	AVOutputStream *ost, **ost_table= NULL;
-	AVInputStream *ist, **ist_table= NULL;
+	AVInputStream *ist = NULL;
 	wxString error;
 	int want_sdp = 1;
 	int bit_buffer_size = 1024*256;
@@ -1289,46 +1117,10 @@
 	if (canceled)
 		return false;
 
-	AVInputFile* file_table = (AVInputFile*) av_mallocz(nb_input_files*sizeof(AVInputFile));
-	if (!file_table)
-		goto fail;
-
-	/* input stream init */
-	j = 0;
-	for (i=0; i<nb_input_files; i++) {
-		is = input_files[i];
-		file_table[i].ist_index = j;
-		file_table[i].nb_streams = is->nb_streams;
-		j += is->nb_streams;;
-	}
-	nb_istreams = j;
-
-	ist_table = (AVInputStream**) av_mallocz(nb_istreams * sizeof(AVInputStream *));
-	if (!ist_table)
-		goto fail;
-
-	for (i=0; i<nb_istreams; i++) {
-		ist = (AVInputStream*) av_mallocz(sizeof(AVInputStream));
-		if (!ist)
-			goto fail;
-		ist_table[i] = ist;
-	}
-	j = 0;
-	for (i=0; i<nb_input_files; i++) {
-		is = input_files[i];
-		for (k=0; k<(int)is->nb_streams; k++) {
-			ist = ist_table[j++];
-			ist->st = is->streams[k];
-			ist->file_index = i;
-			ist->index = k;
-			ist->discard = 1; /* the stream is discarded by default (changed later) */
-
-			if (rate_emu) {
-				ist->start = av_gettime();
-			}
-		}
-	}
-
+	if (rate_emu)
+		for (i = 0; i < nb_input_streams; i++)
+			input_streams[i].start = av_gettime();
+	
 	/* output stream init */
 	nb_ostreams = 0;
 	for (i=0; i<nb_output_files; i++) {
@@ -1350,15 +1142,15 @@
 		int fi = stream_maps[i].file_index;
 		int si = stream_maps[i].stream_index;
 
-		if (fi < 0 || fi > nb_input_files - 1 ||
-			si < 0 || si > file_table[fi].nb_streams - 1) {
+		if (fi < 0 || fi > (int) nb_input_files - 1 ||
+			si < 0 || si > (int) input_files[fi].nb_streams - 1) {
 			wxLogError(wxT("Could not find input stream #%d.%d"), fi, si);
 			return false;
 		}
 		fi = stream_maps[i].sync_file_index;
 		si = stream_maps[i].sync_stream_index;
 		if (fi < 0 || fi> nb_input_files - 1 ||
-				si < 0 || si> file_table[fi].nb_streams - 1) {
+				si < 0 || si > (int) input_files[fi].ctx->nb_streams - 1) {
 			wxLogError(wxT("Could not find sync stream #%d.%d"), fi, si);
 			return false;
 		}
@@ -1379,11 +1171,11 @@
 		for(j=0; j<AVMEDIA_TYPE_NB; j++)
 			nb_frame_threshold[j] += step;
 
-		for(j=0; j<nb_istreams; j++) {
+		for(j=0; j<nb_input_streams; j++) {
 			int skip=0;
-			ist = ist_table[j];
+			ist = &input_streams[j];
 			if(opt_programid){
-				AVFormatContext *f= input_files[ ist->file_index ];
+				AVFormatContext *f= input_files[ist->file_index].ctx;
 				skip=1;
 				for (unsigned int pi=0; pi<f->nb_programs; pi++) {
 					AVProgram *p= f->programs[pi];
@@ -1411,11 +1203,11 @@
 			ost = ost_table[n] = output_streams_for_file[k][i];
 			ost->st = os->streams[i];
 			if (nb_stream_maps > 0) {
-				ost->source_index = file_table[stream_maps[n].file_index].ist_index +
+				ost->source_index = input_files[stream_maps[n].file_index].ist_index +
 					stream_maps[n].stream_index;
 
 				/* Sanity check that the stream types match */
-				if (ist_table[ost->source_index]->st->codec->codec_type
+				if (input_streams[ost->source_index].st->codec->codec_type
 						!= ost->st->codec->codec_type) {
 					wxLogError(wxT("Codec type mismatch for mapping #%d.%d -> #%d.%d"),
 						stream_maps[n].file_index, stream_maps[n].stream_index,
@@ -1426,12 +1218,12 @@
 			} else {
 				/* get corresponding input stream index : we select the first one with the right type */
 				found = 0;
-				for(j=0;j<nb_istreams;j++) {
+				for (j=0; j < nb_input_streams; j++) {
 					int skip=0;
-					ist = ist_table[j];
+					ist = &input_streams[j];
 					if(opt_programid){
 						unsigned int pi,si;
-						AVFormatContext *f= input_files[ ist->file_index ];
+						AVFormatContext *f = input_files[ist->file_index].ctx;
 						skip=1;
 						for(pi=0; pi<f->nb_programs; pi++){
 							AVProgram *p= f->programs[pi];
@@ -1453,8 +1245,8 @@
 				if (!found) {
 					if(! opt_programid) {
 						/* try again and reuse existing stream */
-						for(j=0;j<nb_istreams;j++) {
-							ist = ist_table[j];
+						for (j = 0; j < nb_input_streams; j++) {
+							ist = &input_streams[j];
 							if (   ist->st->codec->codec_type == ost->st->codec->codec_type
 								&& ist->st->discard != AVDISCARD_ALL) {
 								ost->source_index = j;
@@ -1471,10 +1263,10 @@
 					}
 				}
 			}
-			ist = ist_table[ost->source_index];
+			ist = &input_streams[ost->source_index];
 			ist->discard = 0;
 			ost->sync_ist = (nb_stream_maps > 0) ?
-					ist_table[file_table[stream_maps[n].sync_file_index].ist_index +
+					&input_streams[input_files[stream_maps[n].sync_file_index].ist_index +
 					stream_maps[n].sync_stream_index] : ist;
 		}
 	}
@@ -1483,13 +1275,13 @@
 	for (i=0; i<nb_ostreams; i++) {
 		ost = ost_table[i];
 		os = output_files[ost->file_index];
-		ist = ist_table[ost->source_index];
+		ist = &input_streams[ost->source_index];
 
 		codec = ost->st->codec;
 		icodec = ist->st->codec;
 		
 		if (metadata_streams_autocopy)
-			av_metadata_copy(&ost->st->metadata, ist->st->metadata, AV_METADATA_DONT_OVERWRITE); 
+			av_dict_copy(&ost->st->metadata, ist->st->metadata, AV_DICT_DONT_OVERWRITE); 
 		
 		ost->st->disposition = ist->st->disposition;
 		codec->bits_per_raw_sample= icodec->bits_per_raw_sample;
@@ -1520,17 +1312,15 @@
 				goto fail;
 			memcpy(codec->extradata, icodec->extradata, icodec->extradata_size);
 			codec->extradata_size= icodec->extradata_size;
-			if(av_q2d(icodec->time_base)*icodec->ticks_per_frame > av_q2d(ist->st->time_base) && av_q2d(ist->st->time_base) < 1.0/1000){
-				codec->time_base = icodec->time_base;
-				codec->time_base.num *= icodec->ticks_per_frame;
-			} else
-				codec->time_base = ist->st->time_base;
+			if(!copy_tb && av_q2d(icodec->time_base)*icodec->ticks_per_frame > av_q2d(ist->st->time_base) && av_q2d(ist->st->time_base) < 1.0/500){
+                codec->time_base = icodec->time_base;
+                codec->time_base.num *= icodec->ticks_per_frame;
+                av_reduce(&codec->time_base.num, &codec->time_base.den,
+                          codec->time_base.num, codec->time_base.den, INT_MAX);
+            } else
+                codec->time_base = ist->st->time_base; 
 			switch (codec->codec_type) {
 			case AVMEDIA_TYPE_AUDIO:
-				if(audio_volume != 256) {
-					wxLogError(wxT("-acodec copy and -vol are incompatible (frames are not decoded)"));
-					return false;
-				}
 				codec->channel_layout = icodec->channel_layout;
 				codec->sample_rate = icodec->sample_rate;
 				codec->channels = icodec->channels;
@@ -1566,12 +1356,26 @@
 				return false;
 			}
 		} else {
+			if (!ost->enc)
+				ost->enc = avcodec_find_encoder(ost->st->codec->codec_id);
 			switch (codec->codec_type) {
 			case AVMEDIA_TYPE_AUDIO:
+				{
 				ost->fifo= av_fifo_alloc(1024);
 				if(!ost->fifo)
 					goto fail;
 				ost->reformat_pair = MAKE_SFMT_PAIR(AV_SAMPLE_FMT_NONE,AV_SAMPLE_FMT_NONE);
+				if (!codec->sample_rate) {
+					codec->sample_rate = icodec->sample_rate;
+					if (icodec->lowres)
+						codec->sample_rate >>= icodec->lowres;
+				}
+				choose_sample_rate(ost->st, ost->enc);
+				codec->time_base = (AVRational){1, codec->sample_rate};
+				if (!codec->channels)
+					codec->channels = icodec->channels;
+				if (av_get_channel_layout_nb_channels(codec->channel_layout) != codec->channels)
+					codec->channel_layout = 0;
 				ost->audio_resample = codec->sample_rate != icodec->sample_rate || audio_sync_method > 1;
 				icodec->request_channels = codec->channels;
 				ist->decoding_needed = 1;
@@ -1579,12 +1383,21 @@
                 ost->resample_sample_fmt  = icodec->sample_fmt;
                 ost->resample_sample_rate = icodec->sample_rate;
                 ost->resample_channels    = icodec->channels;
+			}
 				break;
 			case AVMEDIA_TYPE_VIDEO:
+				{
+				if (codec->pix_fmt == PIX_FMT_NONE)
+					codec->pix_fmt = icodec->pix_fmt;
+				choose_pixel_fmt(ost->st, ost->enc);
 				if (ost->st->codec->pix_fmt == PIX_FMT_NONE) {
 					wxLogError(wxT("Video pixel format is unknown, stream cannot be encoded"));
 					return false;
 				}
+                if (!codec->width || !codec->height) {
+                    codec->width  = icodec->width;
+                    codec->height = icodec->height;
+                }
 				ost->video_resample = codec->width != icodec->width || codec->height != icodec->height ||
 						codec->pix_fmt != icodec->pix_fmt; 
 				if (ost->video_resample) {
@@ -1595,11 +1408,25 @@
 				ost->resample_pix_fmt= icodec->pix_fmt;
 				ost->encoding_needed = 1;
 				ist->decoding_needed = 1;
+
+                if (!ost->frame_rate.num)
+                    ost->frame_rate = ist->st->r_frame_rate.num ? ist->st->r_frame_rate : (AVRational){25,1};
+                if (ost->enc && ost->enc->supported_framerates && !force_fps) {
+                    int idx = av_find_nearest_q_idx(ost->frame_rate, ost->enc->supported_framerates);
+                    ost->frame_rate = ost->enc->supported_framerates[idx];
+                }
+                codec->time_base = (AVRational){ost->frame_rate.den, ost->frame_rate.num};
+                if(   av_q2d(codec->time_base) < 0.001 && video_sync_method
+                   && (video_sync_method==1 || (video_sync_method<0 && !(os->oformat->flags & AVFMT_VARIABLE_FPS)))){
+                    av_log(os, AV_LOG_WARNING, "Frame rate very high for a muxer not effciciently supporting it.\n"
+                                               "Please consider specifiying a lower framerate, a different muxer or -vsync 2\n");
+                }
 				
-                if (configure_filters(ist, ost)) {
+                if (configure_video_filters(ist, ost)) {
                     wxLogError(wxT("Error opening filters!"));
                     return false;
                 }
+				}
 				break;
 			case AVMEDIA_TYPE_SUBTITLE:
 				ost->encoding_needed = 1;
@@ -1653,10 +1480,8 @@
 	for (i=0; i<nb_ostreams; i++) {
 		ost = ost_table[i];
 		if (ost->encoding_needed) {
-			AVCodec *codec = i < nb_output_codecs ? output_codecs[i] : NULL; 
-			AVCodecContext *dec = ist_table[ost->source_index]->st->codec;
-			if (!codec)
-				codec = avcodec_find_encoder(ost->st->codec->codec_id);
+			AVCodec *codec = ost->enc;
+			AVCodecContext *dec = input_streams[ost->source_index].st->codec;
 			if (!codec) {
 				error = wxString::Format(wxT("Encoder (codec id %d) not found for output stream #%d.%d"),
 						ost->st->codec->codec_id, ost->file_index, ost->index);
@@ -1683,18 +1508,18 @@
 	}
 
 	/* open each decoder */
-	for (i=0; i<nb_istreams; i++) {
-		ist = ist_table[i];
+	for (i = 0; i < nb_input_streams; i++) {
+		ist = &input_streams[i];
 		if (ist->decoding_needed) {
 			AVCodec *codec = avcodec_find_decoder(ist->st->codec->codec_id);
 			if (!codec) {
 				wxLogError(wxT("Decoder (codec id %d) not found for input stream #%d.%d"),
-						ist->st->codec->codec_id, ist->file_index, ist->index);
+						ist->st->codec->codec_id, ist->file_index, ist->st->index);
 				return false;
 			}
 			if (avcodec_open(ist->st->codec, codec) < 0) {
 				wxLogError(wxT("Error while opening decoder for input stream #%d.%d"),
-						ist->file_index, ist->index);
+						ist->file_index, ist->st->index);
 				return false;
 			}
 			//if (ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO)
@@ -1703,20 +1528,68 @@
 	}
 
 	/* init pts */
-	for (i=0; i<nb_istreams; i++) {
+	for (i = 0; i < nb_input_streams; i++) {
 		AVStream *st;
-		ist = ist_table[i];
+		ist = &input_streams[i];
 		st= ist->st;
 		ist->pts = st->avg_frame_rate.num ? - st->codec->has_b_frames*AV_TIME_BASE / av_q2d(st->avg_frame_rate) : 0;
 		ist->next_pts = AV_NOPTS_VALUE;
 		ist->is_start = 1;
 	}
+	
+	/* set meta data information from input file if required */
+    for (i=0;i<nb_meta_data_maps;i++) {
+        AVFormatContext *files[2];
+        AVDictionary    **meta[2];
+        int j;
 
+#define METADATA_CHECK_INDEX(index, nb_elems, desc)\
+        if ((index) < 0 || (index) >= (int) (nb_elems)) {\
+        	error = wxString::Format(wxT("Invalid %s index %d while processing metadata maps."), (desc), (index));\
+            ret = AVERROR(EINVAL);\
+            goto dump_format;\
+        }
+
+        int out_file_index = meta_data_maps[i][0].file;
+        int in_file_index = meta_data_maps[i][1].file;
+        if (in_file_index < 0 || out_file_index < 0)
+            continue;
+        METADATA_CHECK_INDEX(out_file_index, nb_output_files, "output file")
+        METADATA_CHECK_INDEX(in_file_index, nb_input_files, "input file")
+
+        files[0] = output_files[out_file_index];
+        files[1] = input_files[in_file_index].ctx;
+
+        for (j = 0; j < 2; j++) {
+            AVMetaDataMap *map = &meta_data_maps[i][j];
+
+            switch (map->type) {
+            case 'g':
+                meta[j] = &files[j]->metadata;
+                break;
+            case 's':
+                METADATA_CHECK_INDEX(map->index, files[j]->nb_streams, "stream")
+                meta[j] = &files[j]->streams[map->index]->metadata;
+                break;
+            case 'c':
+                METADATA_CHECK_INDEX(map->index, files[j]->nb_chapters, "chapter")
+                meta[j] = &files[j]->chapters[map->index]->metadata;
+                break;
+            case 'p':
+                METADATA_CHECK_INDEX(map->index, files[j]->nb_programs, "program")
+                meta[j] = &files[j]->programs[map->index]->metadata;
+                break;
+            }
+        }
+
+        av_dict_copy(meta[0], *meta[1], AV_DICT_DONT_OVERWRITE);
+    }
+    
 	/* copy global metadata by default */
 	if (metadata_global_autocopy) {
 		
 		for (i = 0; i < nb_output_files; i++)
-			av_metadata_copy(&output_files[i]->metadata, input_files[0]->metadata, AV_METADATA_DONT_OVERWRITE);
+			av_dict_copy(&output_files[i]->metadata, input_files[0].ctx->metadata, AV_DICT_DONT_OVERWRITE);
 	}
 
     /* copy chapters according to chapter maps */
@@ -1742,7 +1615,7 @@
 	/* copy chapters from the first input file that has them*/
 	if (!nb_chapter_maps)
 		for (i = 0; i < nb_input_files; i++) {
-			if (!input_files[i]->nb_chapters)
+			if (!input_files[i].ctx->nb_chapters)
 				continue;
 
 			for (j = 0; j < nb_output_files; j++)
@@ -1776,10 +1649,10 @@
 		for(i=0;i<nb_ostreams;i++) {
 			ost = ost_table[i];
 			wxString msg = wxString::Format(wxT("  Stream #%d.%d -> #%d.%d"),
-					ist_table[ost->source_index]->file_index, ist_table[ost->source_index]->index,
+					input_streams[ost->source_index].file_index, input_streams[ost->source_index].st->index,
 					ost->file_index, ost->index);
-			if (ost->sync_ist != ist_table[ost->source_index])
-				msg += wxString::Format(wxT(" [sync #%d.%d]"), ost->sync_ist->file_index, ost->sync_ist->index);
+			if (ost->sync_ist != &input_streams[ost->source_index])
+				msg += wxString::Format(wxT(" [sync #%d.%d]"), ost->sync_ist->file_index, ost->sync_ist->st->index);
 			wxLogMessage(msg);
 		}
 	}
@@ -1815,12 +1688,12 @@
 			double ipts, opts;
 			ost = ost_table[i];
 			os = output_files[ost->file_index];
-			ist = ist_table[ost->source_index];
+			ist = &input_streams[ost->source_index];
 			if (ist->is_past_recording_time || no_packet[ist->file_index])
 				continue;
 			opts = ost->st->pts.val * av_q2d(ost->st->time_base);
 			ipts = (double)ist->pts;
-			if (!file_table[ist->file_index].eof_reached) {
+			if (!input_files[ist->file_index].eof_reached) {
 				if (ipts < ipts_min) {
 					ipts_min = ipts;
 					if (input_sync)
@@ -1853,7 +1726,7 @@
 			break;
 
 		/* read a frame from it and output it in the fifo */
-		is = input_files[file_index];
+		is = input_files[file_index].ctx;
 		ret= av_read_frame(is, &pkt);
 		if(ret == AVERROR(EAGAIN)){
 			no_packet[file_index]=1;
@@ -1861,7 +1734,7 @@
 			continue;
 		}
 		if (ret < 0) {
-			file_table[file_index].eof_reached = 1;
+			input_files[file_index].eof_reached = 1;
 			if (opt_shortest)
 				break;
 			else
@@ -1876,11 +1749,11 @@
 //		}
 		
 		/* the following test is needed in case new streams appear
-		 dynamically in stream : we ignore them */
-		if (pkt.stream_index >= file_table[file_index].nb_streams)
+		   dynamically in stream : we ignore them */
+		if (pkt.stream_index >= (int) input_files[file_index].nb_streams)
 			goto discard_packet;
-		ist_index = file_table[file_index].ist_index + pkt.stream_index;
-		ist = ist_table[ist_index];
+		ist_index = input_files[file_index].ist_index + pkt.stream_index;
+		ist = &input_streams[ist_index];
 		if (ist->discard)
 			goto discard_packet;
 		
@@ -1926,7 +1799,7 @@
 		//wxLogMessage(wxT("read #%d.%d size=%d"), ist->file_index, ist->index, pkt.size);
 		if (!OutputPacket(ist, ist_index, ost_table, nb_ostreams, &pkt, bit_buffer_size, bit_buffer)) {
 			if (verbose >= 0)
-				wxLogMessage(wxT("Error while decoding stream #%d.%d"), ist->file_index, ist->index);
+				wxLogMessage(wxT("Error while decoding stream #%d.%d"), ist->file_index, ist->st->index);
 			if (exit_on_error)
 				return false;
 			av_free_packet(&pkt);
@@ -1941,8 +1814,8 @@
 	}
 	
 	/* at the end of stream, we must flush the decoder buffers */
-	for (i=0; i<nb_istreams; i++) {
-		ist = ist_table[i];
+	for (i = 0; i < nb_input_streams; i++) {
+		ist = &input_streams[i];
 		if (ist->decoding_needed)
 			OutputPacket(ist, i, ost_table, nb_ostreams, NULL, bit_buffer_size, bit_buffer);
 	}
@@ -1967,8 +1840,8 @@
 	}
 	
 	/* close each decoder */
-	for (i=0; i<nb_istreams; i++) {
-		ist = ist_table[i];
+	for (i = 0; i < nb_input_streams; i++) {
+		ist = &input_streams[i];
 		if (ist->decoding_needed) {
 			avcodec_close(ist->st->codec);
 		}
@@ -1978,15 +1851,7 @@
 	ret = 0;
 fail:
 	av_freep(&bit_buffer);
-	av_free(file_table);
 	
-	if (ist_table) {
-		for (i=0; i<nb_istreams; i++) {
-			ist = ist_table[i];
-			av_free(ist);
-		}
-		av_free(ist_table);
-	}
 	if (ost_table) {
 		for (i=0; i<nb_ostreams; i++) {
 			ost = ost_table[i];
@@ -2000,7 +1865,7 @@
 				av_fifo_free(ost->fifo); /* works even if fifo is not initialized but set to zero */
 				av_freep(&ost->st->codec->subtitle_header);
 				av_free(ost->resample_frame.data[0]);
-//				av_free(ost->forced_kf_pts);
+				av_free(ost->forced_kf_pts);
 				if (ost->video_resample)
 					sws_freeContext(ost->img_resample_ctx);
 				if (ost->resample)
@@ -2029,15 +1894,15 @@
 	AVFormatContext *os;
 	AVOutputStream *ost;
 	int ret, i;
-	int got_picture;
+	int got_output;
 	AVFrame picture;
-	void *buffer_to_free;
+	void *buffer_to_free = NULL;
 	unsigned int samples_size = 0;
 	AVSubtitle subtitle, *subtitle_to_free;
     int frame_available;
 	
 	AVPacket avpkt;
-	int bps = av_get_bits_per_sample_fmt(ist->st->codec->sample_fmt)>>3;
+	int bps = av_get_bytes_per_sample(ist->st->codec->sample_fmt);
 	
 	if(ist->next_pts == (int64_t) AV_NOPTS_VALUE)
 		ist->next_pts= ist->pts;
@@ -2056,7 +1921,7 @@
 		ist->next_pts = ist->pts = av_rescale_q(pkt->dts, ist->st->time_base, AV_TIME_BASE_Q);
 	
 	//while we have more to decode or while the decoder did output something on EOF
-	while (avpkt.size > 0 || (!pkt && ist->next_pts != ist->pts)) {
+	while (avpkt.size > 0 || (!pkt && got_output)) {
 		uint8_t *data_buf, *decoded_data_buf;
 		int data_size, decoded_data_size;
 	handle_eof:
@@ -2090,9 +1955,10 @@
 				avpkt.data += ret;
 				avpkt.size -= ret;
 				data_size   = ret;
+				got_output  = decoded_data_size > 0;
 				// Some bug in mpeg audio decoder gives
 				// decoded_data_size < 0, it seems they are overflows
-				if (decoded_data_size <= 0) {
+				if (!got_output) {
 					// no audio frame
 					continue;
 				}
@@ -2106,11 +1972,11 @@
 				// XXX: allocate picture correctly
 				avcodec_get_frame_defaults(&picture);
 				
-				ret = avcodec_decode_video2(ist->st->codec, &picture, &got_picture, &avpkt);
+				ret = avcodec_decode_video2(ist->st->codec, &picture, &got_output, &avpkt);
 				ist->st->quality= picture.quality;
 				if (ret < 0)
 					goto fail_decode;
-				if (!got_picture) {
+				if (!got_output) {
 					// no picture yet
 					goto discard_packet;
 				}
@@ -2121,12 +1987,14 @@
 							/ ist->st->codec->time_base.den;
 				}
 				avpkt.size = 0;
+				buffer_to_free = NULL;
+				pre_process_video_frame(ist, (AVPicture *)&picture, &buffer_to_free);
 				break;
 			case AVMEDIA_TYPE_SUBTITLE:
-				ret = avcodec_decode_subtitle2(ist->st->codec, &subtitle, &got_picture, &avpkt);
+				ret = avcodec_decode_subtitle2(ist->st->codec, &subtitle, &got_output, &avpkt);
 				if (ret < 0)
 					goto fail_decode;
-				if (!got_picture) {
+				if (!got_output) {
 					goto discard_packet;
 				}
 				subtitle_to_free = &subtitle;
@@ -2157,34 +2025,27 @@
 			avpkt.size = 0;
 		}
 		
-		buffer_to_free = NULL;
-		if (ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
-			pre_process_video_frame(ist, (AVPicture *)&picture, &buffer_to_free);
+		if(ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO)
+		if (start_time == 0 || ist->pts >= start_time) {
+			for(i=0;i<nb_ostreams;i++) {
+				ost = ost_table[i];
+				if (ost->input_video_filter && ost->source_index == ist_index) {
+					if (!picture.sample_aspect_ratio.num)
+						picture.sample_aspect_ratio = ist->st->sample_aspect_ratio;
+					picture.pts = ist->pts;
+
+					av_vsrc_buffer_add_frame(ost->input_video_filter, &picture, AV_VSRC_BUF_FLAG_OVERWRITE);
+				}
+			}
 		}
-		
-        if(ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO){
-            for(i=0;i<nb_ostreams;i++) {
-                ost = ost_table[i];
-                if (ost->input_video_filter && ost->source_index == ist_index) {
-                    AVRational sar;
-                    if (ist->st->sample_aspect_ratio.num) sar = ist->st->sample_aspect_ratio;
-                    else                                  sar = ist->st->codec->sample_aspect_ratio;
-                    // add it to be filtered
-                    av_vsrc_buffer_add_frame2(ost->input_video_filter, &picture,
-                                             ist->pts,
-                                             sar, ist->st->codec->width, ist->st->codec->height,
-                                             ist->st->codec->pix_fmt, "0:0");
-                }
-            }
-        }
         
 		// preprocess audio (volume)
 		if (ist->st->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
-			if (audio_volume != 256) {
+			if (m_audioVolume.find(ist_index) != m_audioVolume.end() && m_audioVolume[ist_index] != 256) {
 				short *volp;
 				volp = samples;
 				for (i=0; i<(int)(decoded_data_size / sizeof(short)); i++) {
-					int v = ((*volp) * audio_volume + 128) >> 8;
+					int v = ((*volp) * m_audioVolume[ist_index] + 128) >> 8;
 					if (v < -32768)
 						v = -32768;
 					if (v > 32767)
@@ -2209,14 +2070,18 @@
 				
 				ost = ost_table[i];
 				if (ost->source_index == ist_index) {
-                frame_available = ist->st->codec->codec_type != AVMEDIA_TYPE_VIDEO ||
-                    !ost->output_video_filter || avfilter_poll_frame(ost->output_video_filter->inputs[0]);
-                while (frame_available) {
-                    AVRational ist_pts_tb;
-                    if (ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO && ost->output_video_filter)
-                        get_filtered_video_frame(ost->output_video_filter, &picture, &ost->picref, &ist_pts_tb);
-                    if (ost->picref)
-                        ist->pts = av_rescale_q(ost->picref->pts, ist_pts_tb, AV_TIME_BASE_Q);
+				frame_available = ist->st->codec->codec_type != AVMEDIA_TYPE_VIDEO ||
+					!ost->output_video_filter || avfilter_poll_frame(ost->output_video_filter->inputs[0]);
+				while (frame_available) {
+					if (ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO && ost->output_video_filter) {
+						AVRational ist_pts_tb = ost->output_video_filter->inputs[0]->time_base;
+						if (av_vsink_buffer_get_video_buffer_ref(ost->output_video_filter, &ost->picref, 0) < 0)
+							goto cont;
+						if (ost->picref) {
+							avfilter_fill_frame_from_video_buffer_ref(&picture, ost->picref);
+							ist->pts = av_rescale_q(ost->picref->pts, ist_pts_tb, AV_TIME_BASE_Q);
+						}
+					}
 					os = output_files[ost->file_index];
 					
 					// set the input output pts pairs
@@ -2232,7 +2097,7 @@
 							break;
 						case AVMEDIA_TYPE_VIDEO:
                             if (ost->picref->video)
-                                ost->st->codec->sample_aspect_ratio = ost->picref->video->pixel_aspect;
+                                ost->st->codec->sample_aspect_ratio = ost->picref->video->sample_aspect_ratio;
 							if (!DoVideoOut(os, ost, ist, &picture, &frame_size, bit_buffer_size, bit_buffer))
 								return false;
 //							if (vstats_filename && frame_size)
@@ -2249,6 +2114,7 @@
 						}
 					} else {
 						AVFrame avframe; //FIXME/XXX remove this
+						AVPicture pict;
 						AVPacket opkt;
 						int64_t ost_tb_start_time= av_rescale_q(start_time, AV_TIME_BASE_Q, ost->st->time_base);
 						
@@ -2298,6 +2164,14 @@
 							opkt.size = data_size;
 						}
 						
+						if (os->oformat->flags & AVFMT_RAWPICTURE) {
+							/* store AVPicture in AVPacket, as expected by the output format */
+							avpicture_fill(&pict, opkt.data, ost->st->codec->pix_fmt, ost->st->codec->width, ost->st->codec->height);
+							opkt.data = (uint8_t *)&pict;
+							opkt.size = sizeof(AVPicture);
+							opkt.flags |= AV_PKT_FLAG_KEY;
+						}
+						
 						if (!WriteFrame(os, &opkt, ost->st->codec, ost->bitstream_filters))
 							return false;
 						
@@ -2308,8 +2182,7 @@
 					cont:
 					frame_available = (ist->st->codec->codec_type == AVMEDIA_TYPE_VIDEO) &&
 							ost->output_video_filter && avfilter_poll_frame(ost->output_video_filter->inputs[0]);
-					if(ost->picref)
-						avfilter_unref_buffer(ost->picref);
+					avfilter_unref_buffer(ost->picref);
 				}
 			}
 		}
@@ -2348,7 +2221,7 @@
 							ret = 0;
 							// encode any samples remaining in fifo
  							if (fifo_bytes > 0) {
-								int osize = av_get_bits_per_sample_fmt(enc->sample_fmt) >> 3;
+								int osize = av_get_bytes_per_sample(enc->sample_fmt);
 								int fs_tmp = enc->frame_size;
 								av_fifo_generic_read(ost->fifo, audio_buf, fifo_bytes, NULL);
 								if (enc->codec->capabilities & CODEC_CAP_SMALL_LAST_FRAME) {
@@ -2447,11 +2320,11 @@
 	int64_t audio_out_size, audio_buf_size;
 	int64_t allocated_for_size= size;
 	
-	int size_out, frame_bytes, ret;
+	int size_out, frame_bytes, ret, resample_changed;
 	AVCodecContext *enc= ost->st->codec;
 	AVCodecContext *dec= ist->st->codec;
-	int osize= av_get_bits_per_sample_fmt(enc->sample_fmt)/8;
-	int isize= av_get_bits_per_sample_fmt(dec->sample_fmt)/8;
+	int osize= av_get_bytes_per_sample(enc->sample_fmt);
+	int isize= av_get_bytes_per_sample(dec->sample_fmt);
 	const int coded_bps = av_get_bits_per_sample(enc->codec->id);
 
 need_realloc:
@@ -2481,18 +2354,42 @@
 	if (enc->channels != dec->channels)
 		ost->audio_resample = 1;
 	
-	if (ost->audio_resample && !ost->resample) {
-		if (dec->sample_fmt != SAMPLE_FMT_S16)
-			wxLogWarning(wxT("Warning, using s16 intermediate sample format for resampling"));
-		ost->resample = av_audio_resample_init(enc->channels, dec->channels,
-				enc->sample_rate, dec->sample_rate,
-				enc->sample_fmt, dec->sample_fmt,
-				16, 10, 0, 0.8);
-		if (!ost->resample) {
-			wxLogError(wxT("Can not resample %d channels @ %d Hz to %d channels @ %d Hz"),
-					dec->channels, dec->sample_rate,
-					enc->channels, enc->sample_rate);
-			return false;
+	resample_changed = ost->resample_sample_fmt  != dec->sample_fmt ||
+					   ost->resample_channels    != dec->channels   ||
+					   ost->resample_sample_rate != dec->sample_rate;
+	
+	if ((ost->audio_resample && !ost->resample) || resample_changed) {
+		if (resample_changed) {
+			av_log(NULL, AV_LOG_INFO, "Input stream #%d.%d frame changed from rate:%d fmt:%s ch:%d to rate:%d fmt:%s ch:%d\n",
+				   ist->file_index, ist->st->index,
+				   ost->resample_sample_rate, av_get_sample_fmt_name(ost->resample_sample_fmt), ost->resample_channels,
+				   dec->sample_rate, av_get_sample_fmt_name(dec->sample_fmt), dec->channels);
+			ost->resample_sample_fmt  = dec->sample_fmt;
+			ost->resample_channels    = dec->channels;
+			ost->resample_sample_rate = dec->sample_rate;
+			if (ost->resample)
+				audio_resample_close(ost->resample);
+		}
+		/* if audio_sync_method is >1 the resampler is needed for audio drift compensation */
+		if (audio_sync_method <= 1 &&
+				ost->resample_sample_fmt  == enc->sample_fmt &&
+				ost->resample_channels    == enc->channels   &&
+				ost->resample_sample_rate == enc->sample_rate) {
+			ost->resample = NULL;
+			ost->audio_resample = 0;
+		} else {
+			if (dec->sample_fmt != SAMPLE_FMT_S16)
+				wxLogWarning(wxT("Warning, using s16 intermediate sample format for resampling"));
+			ost->resample = av_audio_resample_init(enc->channels, dec->channels,
+					enc->sample_rate, dec->sample_rate,
+					enc->sample_fmt, dec->sample_fmt,
+					16, 10, 0, 0.8);
+			if (!ost->resample) {
+				wxLogError(wxT("Can not resample %d channels @ %d Hz to %d channels @ %d Hz"),
+						dec->channels, dec->sample_rate,
+						enc->channels, enc->sample_rate);
+				return false;
+			}
 		}
 	}
 	
@@ -2619,7 +2516,7 @@
 			pkt.size= ret;
 			if(enc->coded_frame && enc->coded_frame->pts != (int64_t) AV_NOPTS_VALUE)
 				pkt.pts= av_rescale_q(enc->coded_frame->pts, enc->time_base, ost->st->time_base);
-			pkt.flags |= PKT_FLAG_KEY;
+			pkt.flags |= AV_PKT_FLAG_KEY;
 			if (!WriteFrame(s, &pkt, ost->st->codec, ost->bitstream_filters))
 				return false;
 			
@@ -2704,7 +2601,7 @@
 bool wxFfmpegMediaTranscoder::DoVideoOut(AVFormatContext *s, AVOutputStream *ost,
 		AVInputStream *ist, AVFrame *in_picture, int *frame_size,
 		int bit_buffer_size, uint8_t* bit_buffer) {
-	int nb_frames, i, ret, av_unused resample_changed;
+	int nb_frames, i, ret;
 	AVFrame *final_picture, *formatted_picture;
 	AVCodecContext *enc, *dec;
 	double sync_ipts;
@@ -2787,15 +2684,13 @@
 			// handles sameq here. This is not correct because it may not be a global option
 			big_picture.quality = same_quality ? (int) ist->st->quality : (int) ost->st->quality;
 			if (!me_threshold)
-				big_picture.pict_type = 0;
-//			big_picture.pts = AV_NOPTS_VALUE;
+				big_picture.pict_type = (AVPictureType) 0;
 			big_picture.pts= ost->sync_opts;
-//			big_picture.pts= av_rescale(ost->sync_opts, AV_TIME_BASE*(int64_t)enc->time_base.num, enc->time_base.den);
-//			if (ost->forced_kf_index < ost->forced_kf_count &&
-//				big_picture.pts >= ost->forced_kf_pts[ost->forced_kf_index]) {
-//				big_picture.pict_type = AV_PICTURE_TYPE_I;
-//				ost->forced_kf_index++;
-//			}
+			if (ost->forced_kf_index < ost->forced_kf_count &&
+				big_picture.pts >= ost->forced_kf_pts[ost->forced_kf_index]) {
+				big_picture.pict_type = AV_PICTURE_TYPE_I;
+				ost->forced_kf_index++;
+			}
 			ret = avcodec_encode_video(enc, bit_buffer, bit_buffer_size, &big_picture);
 			if (ret < 0) {
 				wxLogError(wxT("Video encoding failed"));
@@ -2806,17 +2701,12 @@
 				pkt.size= ret;
 				if(enc->coded_frame->pts != (int64_t) AV_NOPTS_VALUE)
 					pkt.pts= av_rescale_q(enc->coded_frame->pts, enc->time_base, ost->st->time_base);
-				//av_log(NULL, AV_LOG_DEBUG, "encoder -> %"PRId64"/%"PRId64"\n",
-				//pkt.pts != AV_NOPTS_VALUE ? av_rescale(pkt.pts, enc->time_base.den, AV_TIME_BASE*(int64_t)enc->time_base.num) : -1,
-				//pkt.dts != AV_NOPTS_VALUE ? av_rescale(pkt.dts, enc->time_base.den, AV_TIME_BASE*(int64_t)enc->time_base.num) : -1);
-
+				
 				if(enc->coded_frame->key_frame)
 					pkt.flags |= AV_PKT_FLAG_KEY;
 				WriteFrame(s, &pkt, ost->st->codec, ost->bitstream_filters);
 				*frame_size = ret;
 				video_size += ret;
-				//wxLogError(wxT("Frame: %3d size: %5d type: %d"),
-				//		enc->frame_number-1, ret, enc->pict_type);
 				// if two pass, output log
 				if (ost->logfile && enc->stats_out) {
 					fprintf(ost->logfile, "%s", enc->stats_out);
@@ -2896,7 +2786,8 @@
 	int64_t total_size;
 	AVCodecContext *enc;
 	int frame_number, vid, i;
-	double bitrate, ti1, pts;
+	double bitrate;
+	int64_t pts = INT64_MAX;
 	static int64_t last_time = -1;
 	static int qp_histogram[52];
 	
@@ -2920,11 +2811,13 @@
 		total_size= avio_tell(oc->pb); 
 	
 	wxString msg;
-	ti1 = 1e10;
 	vid = 0;
 	for (i=0; i<nb_ostreams; i++) {
+		float q = -1;
 		ost = ost_table[i];
 		enc = ost->st->codec;
+		if (!ost->st->stream_copy && enc->coded_frame)
+			q = enc->coded_frame->quality/(float)FF_QP2LAMBDA;
 		if (vid && enc->codec_type == AVMEDIA_TYPE_VIDEO) {
 			msg += wxString::Format(wxT("q=%2.1f "),
 					!ost->st->stream_copy ?	enc->coded_frame->quality/(float)FF_QP2LAMBDA : -1);
@@ -2940,7 +2833,7 @@
 				msg += wxString::Format(wxT("L"));
 			if (qp_hist) {
 				int j;
-				int qp = (int) rint(enc->coded_frame->quality/(float)FF_QP2LAMBDA);
+				int qp = lrintf(q);
 				if (qp>=0 && qp < (int) (FF_ARRAY_ELEMS(qp_histogram)))
 					qp_histogram[qp]++;
 				for (j=0; j<32; j++)
@@ -2971,18 +2864,22 @@
 			vid = 1;
 		}
 		// compute min output value
-		pts = (double)ost->st->pts.val * av_q2d(ost->st->time_base);
-		if ((pts < ti1) && (pts > 0))
-			ti1 = pts;
+		pts = FFMIN(pts, av_rescale_q(ost->st->pts.val, ost->st->time_base, AV_TIME_BASE_Q));
 	}
-	if (ti1 < 0.01)
-		ti1 = 0.01;
 	
 	if (verbose || is_last_report) {
-		bitrate = (double)(total_size * 8) / ti1 / 1000.0;
+		int hours, mins, secs, us;
+		secs = pts / AV_TIME_BASE;
+		us = pts % AV_TIME_BASE;
+		mins = secs / 60;
+		secs %= 60;
+		hours = mins / 60;
+		mins %= 60;
+
+		bitrate = pts ? total_size * 8 / (pts / 1000.0) : 0;
 		
-		msg += wxString::Format(wxT("size=%8.0fkB time=%0.2f bitrate=%6.1fkbits/s"),
-				(double)total_size / 1024, ti1, bitrate);
+		msg += wxString::Format(wxT("size=%8.0fkB time=%02d:%02d:%02d.%02d bitrate=%6.1fkbits/s"),
+				(double) total_size / 1024, hours, mins, secs, (100 * us) / AV_TIME_BASE, bitrate);
 		
 		if (nb_frames_dup || nb_frames_drop)
 			msg += wxString::Format(wxT(" dup=%d drop=%d"), nb_frames_dup, nb_frames_drop);
@@ -3013,10 +2910,9 @@
 	}
 	nb_output_files = 0;
 	for (int i=0; i<nb_input_files; i++) {
-		av_close_input_file(input_files[i]);
+		av_close_input_file(input_files[i].ctx);
 		av_free(input_files_ts_scale[i]);
 	}
-	nb_input_files = 0;
 	
 	av_freep(&intra_matrix);
 	av_freep(&inter_matrix);
@@ -3025,11 +2921,14 @@
 		fclose(vstats_file);
 	av_freep(&vstats_filename);
 	
-	av_freep(&output_codecs);
-	nb_output_codecs = 0;
 	av_freep(&stream_maps);
 	nb_stream_maps = 0;
 	
+	av_freep(&input_streams);
+	nb_input_streams = 0;
+	av_freep(&input_files);
+	nb_input_files = 0;
+	
 	av_freep(&video_standard);
 	av_freep(&audio_buf);
 	av_freep(&audio_out);
