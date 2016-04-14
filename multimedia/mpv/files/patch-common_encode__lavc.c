--- common/encode_lavc.c.orig	2016-04-11 17:10:54 UTC
+++ common/encode_lavc.c
@@ -21,6 +21,7 @@
 
 #include <libavutil/avutil.h>
 
+#include "config.h"
 #include "encode_lavc.h"
 #include "common/global.h"
 #include "common/msg.h"
@@ -291,32 +292,20 @@ int encode_lavc_start(struct encode_lavc
 
     CHECK_FAIL(ctx, 0);
 
-    if (ctx->expect_video) {
-        unsigned i;
-        for (i = 0; i < ctx->avc->nb_streams; ++i)
-            if (ctx->avc->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
-                break;
-        if (i >= ctx->avc->nb_streams) {
-            if (ctx->avc->oformat->video_codec != AV_CODEC_ID_NONE ||
-                ctx->options->vcodec) {
-                encode_lavc_fail(ctx,
-                    "no video stream succeeded - invalid codec?\n");
-                return 0;
-            }
+    if (ctx->expect_video && ctx->vcc == NULL) {
+        if (ctx->avc->oformat->video_codec != AV_CODEC_ID_NONE ||
+            ctx->options->vcodec) {
+            encode_lavc_fail(ctx,
+                "no video stream succeeded - invalid codec?\n");
+            return 0;
         }
     }
-    if (ctx->expect_audio) {
-        unsigned i;
-        for (i = 0; i < ctx->avc->nb_streams; ++i)
-            if (ctx->avc->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO)
-                break;
-        if (i >= ctx->avc->nb_streams) {
-            if (ctx->avc->oformat->audio_codec != AV_CODEC_ID_NONE ||
-                ctx->options->acodec) {
-                encode_lavc_fail(ctx,
-                    "no audio stream succeeded - invalid codec?\n");
-                return 0;
-            }
+    if (ctx->expect_audio && ctx->acc == NULL) {
+        if (ctx->avc->oformat->audio_codec != AV_CODEC_ID_NONE ||
+            ctx->options->acodec) {
+            encode_lavc_fail(ctx,
+                "no audio stream succeeded - invalid codec?\n");
+            return 0;
         }
     }
 
@@ -387,33 +376,38 @@ void encode_lavc_finish(struct encode_la
         if (ctx->header_written > 0)
             av_write_trailer(ctx->avc);  // this is allowed to fail
 
-        for (i = 0; i < ctx->avc->nb_streams; i++) {
-            switch (ctx->avc->streams[i]->codec->codec_type) {
-            case AVMEDIA_TYPE_VIDEO:
-                if (ctx->twopass_bytebuffer_v) {
-                    char *stats = ctx->avc->streams[i]->codec->stats_out;
-                    if (stats)
-                        stream_write_buffer(ctx->twopass_bytebuffer_v,
-                                            stats, strlen(stats));
-                }
-                break;
-            case AVMEDIA_TYPE_AUDIO:
-                if (ctx->twopass_bytebuffer_a) {
-                    char *stats = ctx->avc->streams[i]->codec->stats_out;
-                    if (stats)
-                        stream_write_buffer(ctx->twopass_bytebuffer_a,
-                                            stats, strlen(stats));
-                }
-                break;
-            default:
-                break;
+        if (ctx->vcc) {
+            if (ctx->twopass_bytebuffer_v) {
+                char *stats = ctx->vcc->stats_out;
+                if (stats)
+                    stream_write_buffer(ctx->twopass_bytebuffer_v,
+                                        stats, strlen(stats));
             }
-            avcodec_close(ctx->avc->streams[i]->codec);
-            talloc_free(ctx->avc->streams[i]->codec->stats_in);
-            av_free(ctx->avc->streams[i]->codec);
+            avcodec_close(ctx->vcc);
+            talloc_free(ctx->vcc->stats_in);
+            av_free(ctx->vcc);
+            ctx->vcc = NULL;
+        }
+
+        if (ctx->acc) {
+            if (ctx->twopass_bytebuffer_a) {
+                char *stats = ctx->acc->stats_out;
+                if (stats)
+                    stream_write_buffer(ctx->twopass_bytebuffer_a,
+                                        stats, strlen(stats));
+            }
+            avcodec_close(ctx->acc);
+            talloc_free(ctx->acc->stats_in);
+            av_free(ctx->acc);
+            ctx->acc = NULL;
+        }
+
+        for (i = 0; i < ctx->avc->nb_streams; i++) {
             av_free(ctx->avc->streams[i]->info);
             av_free(ctx->avc->streams[i]);
         }
+        ctx->vst = NULL;
+        ctx->ast = NULL;
 
         if (ctx->twopass_bytebuffer_v) {
             free_stream(ctx->twopass_bytebuffer_v);
@@ -437,6 +431,7 @@ void encode_lavc_finish(struct encode_la
         }
 
         av_free(ctx->avc);
+        ctx->avc = NULL;
     }
 
     ctx->finished = true;
@@ -461,7 +456,9 @@ void encode_lavc_set_audio_pts(struct en
 
 static void encode_2pass_prepare(struct encode_lavc_context *ctx,
                                  AVDictionary **dictp,
-                                 AVStream *stream, struct stream **bytebuf,
+                                 AVStream *stream,
+                                 AVCodecContext *codec,
+                                 struct stream **bytebuf,
                                  const char *prefix)
 {
     if (!*bytebuf) {
@@ -476,7 +473,7 @@ static void encode_2pass_prepare(struct 
             if (!(*bytebuf = stream_open(buf, ctx->global))) {
                 MP_WARN(ctx, "%s: could not open '%s', "
                        "disabling 2-pass encoding at pass 2\n", prefix, buf);
-                stream->codec->flags &= ~CODEC_FLAG_PASS2;
+                codec->flags &= ~CODEC_FLAG_PASS2;
                 set_to_avdictionary(ctx, dictp, "flags", "-pass2");
             } else {
                 struct bstr content = stream_read_complete(*bytebuf, NULL,
@@ -487,7 +484,7 @@ static void encode_2pass_prepare(struct 
                            prefix, ctx->avc->filename);
                 } else {
                     content.start[content.len] = 0;
-                    stream->codec->stats_in = content.start;
+                    codec->stats_in = content.start;
                 }
                 free_stream(*bytebuf);
                 *bytebuf = NULL;
@@ -506,43 +503,55 @@ static void encode_2pass_prepare(struct 
     }
 }
 
-AVStream *encode_lavc_alloc_stream(struct encode_lavc_context *ctx,
-                                   enum AVMediaType mt)
+int encode_lavc_alloc_stream(struct encode_lavc_context *ctx,
+                             enum AVMediaType mt,
+                             AVStream **stream_out,
+                             AVCodecContext **codec_out)
 {
     AVDictionaryEntry *de;
-    AVStream *stream = NULL;
     char **p;
-    int i;
 
-    CHECK_FAIL(ctx, NULL);
+    *stream_out = NULL;
+    *codec_out = NULL;
 
-    if (ctx->header_written)
-        return NULL;
+    CHECK_FAIL(ctx, -1);
 
-    for (i = 0; i < ctx->avc->nb_streams; ++i)
-        if (ctx->avc->streams[i]->codec->codec_type == mt)
-            // already have a stream of that type, this cannot really happen
-            return NULL;
+    if (ctx->header_written)
+        return -1;
 
     if (ctx->avc->nb_streams == 0) {
         // if this stream isn't stream #0, allocate a dummy stream first for
-        // the next loop to use
+        // the next call to use
         if (mt == AVMEDIA_TYPE_VIDEO && ctx->audio_first) {
             MP_INFO(ctx, "vo-lavc: preallocated audio stream for later use\n");
-            avformat_new_stream(ctx->avc, NULL); // this one is AVMEDIA_TYPE_UNKNOWN for now
+            ctx->ast = avformat_new_stream(
+                ctx->avc, NULL);  // this one is AVMEDIA_TYPE_UNKNOWN for now
         }
         if (mt == AVMEDIA_TYPE_AUDIO && ctx->video_first) {
             MP_INFO(ctx, "ao-lavc: preallocated video stream for later use\n");
-            avformat_new_stream(ctx->avc, NULL); // this one is AVMEDIA_TYPE_UNKNOWN for now
+            ctx->vst = avformat_new_stream(
+                ctx->avc, NULL);  // this one is AVMEDIA_TYPE_UNKNOWN for now
         }
-    } else {
-        // find possibly preallocated stream
-        for (i = 0; i < ctx->avc->nb_streams; ++i)
-            if (ctx->avc->streams[i]->codec->codec_type == AVMEDIA_TYPE_UNKNOWN) // preallocated stream
-                stream = ctx->avc->streams[i];
     }
-    if (!stream)
-        stream = avformat_new_stream(ctx->avc, NULL);
+
+    // already have a stream of that type (this cannot really happen)?
+    switch (mt) {
+    case AVMEDIA_TYPE_VIDEO:
+        if (ctx->vcc != NULL)
+            return -1;
+        if (ctx->vst == NULL)
+            ctx->vst = avformat_new_stream(ctx->avc, NULL);
+        break;
+    case AVMEDIA_TYPE_AUDIO:
+        if (ctx->acc != NULL)
+            return -1;
+        if (ctx->ast == NULL)
+            ctx->ast = avformat_new_stream(ctx->avc, NULL);
+        break;
+    default:
+        encode_lavc_fail(ctx, "requested invalid stream type\n");
+        return -1;
+    }
 
     if (ctx->timebase.den == 0) {
         AVRational r;
@@ -584,13 +593,18 @@ AVStream *encode_lavc_alloc_stream(struc
                 ctx->options->vcodec) {
                 encode_lavc_fail(ctx, "vo-lavc: encoder not found\n");
             }
-            return NULL;
+            return -1;
         }
-        avcodec_get_context_defaults3(stream->codec, ctx->vc);
+#if HAVE_AVCODEC_HAS_CODECPAR
+        ctx->vcc = avcodec_alloc_context3(ctx->vc);
+#else
+        avcodec_get_context_defaults3(ctx->vst->codec, ctx->vc);
+        ctx->vcc = ctx->vst->codec;
+#endif
 
         // Using codec->time_base is deprecated, but needed for older lavf.
-        stream->time_base = ctx->timebase;
-        stream->codec->time_base = ctx->timebase;
+        ctx->vst->time_base = ctx->timebase;
+        ctx->vcc->time_base = ctx->timebase;
 
         ctx->voptions = NULL;
 
@@ -606,10 +620,12 @@ AVStream *encode_lavc_alloc_stream(struc
         if (ctx->avc->oformat->flags & AVFMT_GLOBALHEADER)
             set_to_avdictionary(ctx, &ctx->voptions, "flags", "+global_header");
 
-        encode_2pass_prepare(ctx, &ctx->voptions, stream,
+        encode_2pass_prepare(ctx, &ctx->voptions, ctx->vst, ctx->vcc,
                              &ctx->twopass_bytebuffer_v,
                              "vo-lavc");
-        break;
+        *stream_out = ctx->vst;
+        *codec_out = ctx->vcc;
+        return 0;
 
     case AVMEDIA_TYPE_AUDIO:
         if (!ctx->ac) {
@@ -617,15 +633,20 @@ AVStream *encode_lavc_alloc_stream(struc
                 ctx->options->acodec) {
                 encode_lavc_fail(ctx, "ao-lavc: encoder not found\n");
             }
-            return NULL;
+            return -1;
         }
-        avcodec_get_context_defaults3(stream->codec, ctx->ac);
+#if HAVE_AVCODEC_HAS_CODECPAR
+        ctx->acc = avcodec_alloc_context3(ctx->ac);
+#else
+        avcodec_get_context_defaults3(ctx->ast->codec, ctx->ac);
+        ctx->acc = ctx->ast->codec;
+#endif
 
         // Using codec->time_base is deprecated, but needed for older lavf.
-        stream->time_base = ctx->timebase;
-        stream->codec->time_base = ctx->timebase;
+        ctx->ast->time_base = ctx->timebase;
+        ctx->acc->time_base = ctx->timebase;
 
-        ctx->aoptions = NULL;
+        ctx->aoptions = 0;
 
         if (ctx->options->aopts)
             for (p = ctx->options->aopts; *p; ++p)
@@ -639,49 +660,34 @@ AVStream *encode_lavc_alloc_stream(struc
         if (ctx->avc->oformat->flags & AVFMT_GLOBALHEADER)
             set_to_avdictionary(ctx, &ctx->aoptions, "flags", "+global_header");
 
-        encode_2pass_prepare(ctx, &ctx->aoptions, stream,
+        encode_2pass_prepare(ctx, &ctx->aoptions, ctx->ast, ctx->acc,
                              &ctx->twopass_bytebuffer_a,
                              "ao-lavc");
-        break;
 
-    default:
-        encode_lavc_fail(ctx, "requested invalid stream type\n");
-        return NULL;
+        *stream_out = ctx->ast;
+        *codec_out = ctx->acc;
+        return 0;
     }
 
-    return stream;
-}
-
-AVCodec *encode_lavc_get_codec(struct encode_lavc_context *ctx,
-                               AVStream *stream)
-{
-    CHECK_FAIL(ctx, NULL);
-
-    switch (stream->codec->codec_type) {
-    case AVMEDIA_TYPE_VIDEO:
-        return ctx->vc;
-    case AVMEDIA_TYPE_AUDIO:
-        return ctx->ac;
-    default:
-        break;
-    }
-    return NULL;
+    // Unreachable.
+    return -1;
 }
 
-int encode_lavc_open_codec(struct encode_lavc_context *ctx, AVStream *stream)
+int encode_lavc_open_codec(struct encode_lavc_context *ctx,
+                           AVCodecContext *codec)
 {
     AVDictionaryEntry *de;
     int ret;
 
     CHECK_FAIL(ctx, -1);
 
-    switch (stream->codec->codec_type) {
+    switch (codec->codec_type) {
     case AVMEDIA_TYPE_VIDEO:
         MP_INFO(ctx, "Opening video encoder: %s [%s]\n",
                 ctx->vc->long_name, ctx->vc->name);
 
         if (ctx->vc->capabilities & CODEC_CAP_EXPERIMENTAL) {
-            stream->codec->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;
+            codec->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;
             MP_WARN(ctx, "\n\n"
                        "           ********************************************\n"
                        "           **** Experimental VIDEO codec selected! ****\n"
@@ -701,7 +707,11 @@ int encode_lavc_open_codec(struct encode
                    ctx->vc->name);
         }
 
-        ret = avcodec_open2(stream->codec, ctx->vc, &ctx->voptions);
+        ret = avcodec_open2(codec, ctx->vc, &ctx->voptions);
+#if HAVE_AVCODEC_HAS_CODECPAR
+        if (ret >= 0)
+            ret = avcodec_parameters_from_context(ctx->vst->codecpar, codec);
+#endif
 
         // complain about all remaining options, then free the dict
         for (de = NULL; (de = av_dict_get(ctx->voptions, "", de,
@@ -716,7 +726,7 @@ int encode_lavc_open_codec(struct encode
                 ctx->ac->long_name, ctx->ac->name);
 
         if (ctx->ac->capabilities & CODEC_CAP_EXPERIMENTAL) {
-            stream->codec->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;
+            codec->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;
             MP_WARN(ctx, "\n\n"
                        "           ********************************************\n"
                        "           **** Experimental AUDIO codec selected! ****\n"
@@ -735,7 +745,12 @@ int encode_lavc_open_codec(struct encode
                        "If none of this helps you, try another codec in place of %s.\n\n",
                    ctx->ac->name);
         }
-        ret = avcodec_open2(stream->codec, ctx->ac, &ctx->aoptions);
+
+        ret = avcodec_open2(codec, ctx->ac, &ctx->aoptions);
+#if HAVE_AVCODEC_HAS_CODECPAR
+        if (ret >= 0)
+            ret = avcodec_parameters_from_context(ctx->ast->codecpar, codec);
+#endif
 
         // complain about all remaining options, then free the dict
         for (de = NULL; (de = av_dict_get(ctx->aoptions, "", de,
@@ -757,36 +772,43 @@ int encode_lavc_open_codec(struct encode
     return ret;
 }
 
-void encode_lavc_write_stats(struct encode_lavc_context *ctx, AVStream *stream)
+void encode_lavc_write_stats(struct encode_lavc_context *ctx,
+                             AVCodecContext *codec)
 {
     CHECK_FAIL(ctx, );
 
-    switch (stream->codec->codec_type) {
+    switch (codec->codec_type) {
     case AVMEDIA_TYPE_VIDEO:
         if (ctx->twopass_bytebuffer_v)
-            if (stream->codec->stats_out)
+            if (codec->stats_out)
                 stream_write_buffer(ctx->twopass_bytebuffer_v,
-                                    stream->codec->stats_out,
-                                    strlen(stream->codec->stats_out));
+                                    codec->stats_out,
+                                    strlen(codec->stats_out));
         break;
     case AVMEDIA_TYPE_AUDIO:
         if (ctx->twopass_bytebuffer_a)
-            if (stream->codec->stats_out)
+            if (codec->stats_out)
                 stream_write_buffer(ctx->twopass_bytebuffer_a,
-                                    stream->codec->stats_out,
-                                    strlen(stream->codec->stats_out));
+                                    codec->stats_out,
+                                    strlen(codec->stats_out));
         break;
     default:
         break;
     }
 }
 
-int encode_lavc_write_frame(struct encode_lavc_context *ctx, AVPacket *packet)
+int encode_lavc_write_frame(struct encode_lavc_context *ctx, AVStream *stream,
+                            AVPacket *packet)
 {
     int r;
 
     CHECK_FAIL(ctx, -1);
 
+    if (stream->index != packet->stream_index) {
+        MP_ERR(ctx, "Called encode_lavc_write_frame on the wrong stream\n");
+        return -1;
+    }
+
     if (ctx->header_written <= 0)
         return -1;
 
@@ -795,27 +817,32 @@ int encode_lavc_write_frame(struct encod
         (int)packet->stream_index,
         (int)packet->pts,
         packet->pts
-        * (double)ctx->avc->streams[packet->stream_index]->time_base.num
-        / (double)ctx->avc->streams[packet->stream_index]->time_base.den,
+        * (double)stream->time_base.num
+        / (double)stream->time_base.den,
         (int)packet->dts,
         packet->dts
-        * (double)ctx->avc->streams[packet->stream_index]->time_base.num
-        / (double)ctx->avc->streams[packet->stream_index]->time_base.den,
+        * (double)stream->time_base.num
+        / (double)stream->time_base.den,
         (int)packet->size);
 
-    switch (ctx->avc->streams[packet->stream_index]->codec->codec_type) {
-    case AVMEDIA_TYPE_VIDEO:
-        ctx->vbytes += packet->size;
-        ++ctx->frames;
-        break;
-    case AVMEDIA_TYPE_AUDIO:
-        ctx->abytes += packet->size;
-        ctx->audioseconds += packet->duration
-            * (double)ctx->avc->streams[packet->stream_index]->time_base.num
-            / (double)ctx->avc->streams[packet->stream_index]->time_base.den;
-        break;
-    default:
-        break;
+
+#if HAVE_AVCODEC_HAS_CODECPAR
+    switch (stream->codecpar->codec_type) {
+#else
+    switch (stream->codec->codec_type) {
+#endif
+        case AVMEDIA_TYPE_VIDEO:
+            ctx->vbytes += packet->size;
+            ++ctx->frames;
+            break;
+        case AVMEDIA_TYPE_AUDIO:
+            ctx->abytes += packet->size;
+            ctx->audioseconds += packet->duration
+                    * (double)stream->time_base.num
+                    / (double)stream->time_base.den;
+            break;
+        default:
+            break;
     }
 
     r = av_interleaved_write_frame(ctx->avc, packet);
@@ -1062,11 +1089,12 @@ bool encode_lavc_showhelp(struct mp_log 
     return help_output;
 }
 
-double encode_lavc_getoffset(struct encode_lavc_context *ctx, AVStream *stream)
+double encode_lavc_getoffset(struct encode_lavc_context *ctx,
+                             AVCodecContext *codec)
 {
     CHECK_FAIL(ctx, 0);
 
-    switch (stream->codec->codec_type) {
+    switch (codec->codec_type) {
     case AVMEDIA_TYPE_VIDEO:
         return ctx->options->voffset;
     case AVMEDIA_TYPE_AUDIO:
@@ -1151,49 +1179,49 @@ void encode_lavc_fail(struct encode_lavc
 }
 
 bool encode_lavc_set_csp(struct encode_lavc_context *ctx,
-                         AVStream *stream, enum mp_csp csp)
+                         AVCodecContext *codec, enum mp_csp csp)
 {
     CHECK_FAIL(ctx, NULL);
 
     if (ctx->header_written) {
-        if (stream->codec->colorspace != mp_csp_to_avcol_spc(csp))
+        if (codec->colorspace != mp_csp_to_avcol_spc(csp))
             MP_WARN(ctx, "can not change color space during encoding\n");
         return false;
     }
 
-    stream->codec->colorspace = mp_csp_to_avcol_spc(csp);
+    codec->colorspace = mp_csp_to_avcol_spc(csp);
     return true;
 }
 
 bool encode_lavc_set_csp_levels(struct encode_lavc_context *ctx,
-                                AVStream *stream, enum mp_csp_levels lev)
+                                AVCodecContext *codec, enum mp_csp_levels lev)
 {
     CHECK_FAIL(ctx, NULL);
 
     if (ctx->header_written) {
-        if (stream->codec->color_range != mp_csp_levels_to_avcol_range(lev))
+        if (codec->color_range != mp_csp_levels_to_avcol_range(lev))
             MP_WARN(ctx, "can not change color space during encoding\n");
         return false;
     }
 
-    stream->codec->color_range = mp_csp_levels_to_avcol_range(lev);
+    codec->color_range = mp_csp_levels_to_avcol_range(lev);
     return true;
 }
 
 enum mp_csp encode_lavc_get_csp(struct encode_lavc_context *ctx,
-                                AVStream *stream)
+                                AVCodecContext *codec)
 {
     CHECK_FAIL(ctx, 0);
 
-    return avcol_spc_to_mp_csp(stream->codec->colorspace);
+    return avcol_spc_to_mp_csp(codec->colorspace);
 }
 
 enum mp_csp_levels encode_lavc_get_csp_levels(struct encode_lavc_context *ctx,
-                                              AVStream *stream)
+                                              AVCodecContext *codec)
 {
     CHECK_FAIL(ctx, 0);
 
-    return avcol_range_to_mp_csp_levels(stream->codec->color_range);
+    return avcol_range_to_mp_csp_levels(codec->color_range);
 }
 
 // vim: ts=4 sw=4 et
