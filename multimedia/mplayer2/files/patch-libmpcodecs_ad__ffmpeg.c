--- libmpcodecs/ad_ffmpeg.c.orig	2013-07-09 16:33:13 UTC
+++ libmpcodecs/ad_ffmpeg.c
@@ -23,9 +23,9 @@
 #include <assert.h>

 #include <libavcodec/avcodec.h>
-#include <libavutil/audioconvert.h>
 #include <libavutil/opt.h>
 #include <libavutil/samplefmt.h>
+#include <libavutil/channel_layout.h>

 #include "talloc.h"

@@ -236,7 +236,7 @@ static int init(sh_audio_t *sh_audio)
     sh_audio->context = ctx;
     lavc_context = avcodec_alloc_context3(lavc_codec);
     ctx->avctx = lavc_context;
-    ctx->avframe = avcodec_alloc_frame();
+    ctx->avframe = av_frame_alloc();

     // Always try to set - option only exists for AC3 at the moment
     av_opt_set_double(lavc_context, "drc_scale", opts->drc_level,
@@ -250,7 +250,7 @@ static int init(sh_audio_t *sh_audio)
         lavc_context->block_align = sh_audio->wf->nBlockAlign;
         lavc_context->bits_per_coded_sample = sh_audio->wf->wBitsPerSample;
     }
-    lavc_context->request_channels = opts->audio_output_channels;
+    lavc_context->request_channel_layout = av_get_default_channel_layout(opts->audio_output_channels);
     lavc_context->codec_tag = sh_audio->format; //FOURCC
     lavc_context->codec_type = AVMEDIA_TYPE_AUDIO;
     lavc_context->codec_id = lavc_codec->id; // not sure if required, imho not --A'rpi
@@ -333,7 +333,7 @@ static void uninit(sh_audio_t *sh)
     avresample_free(&ctx->avr);
 #endif
 #if LIBAVCODEC_VERSION_INT >= (54 << 16 | 28 << 8)
-    avcodec_free_frame(&ctx->avframe);
+    av_frame_free(&ctx->avframe);
 #else
     av_free(ctx->avframe);
 #endif
