Some changes are identical to upstream:
http://git.savannah.gnu.org/cgit/bino.git/commit/?id=bcba7045c99f
http://git.savannah.gnu.org/cgit/bino.git/commit/?id=50b7109633fa
http://git.savannah.gnu.org/cgit/bino.git/commit/?id=78023424d4cf

--- src/media_object.cpp.orig	2013-01-27 21:04:48 UTC
+++ src/media_object.cpp
@@ -56,6 +56,23 @@ extern "C"
 
 #include "media_object.h"
 
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(51, 42, 0)
+#define AVPixelFormat PixelFormat
+#define AV_PIX_FMT_BGRA PIX_FMT_BGRA
+#define AV_PIX_FMT_YUV420P PIX_FMT_YUV420P
+#define AV_PIX_FMT_YUV420P10 PIX_FMT_YUV420P10
+#define AV_PIX_FMT_YUV422P PIX_FMT_YUV422P
+#define AV_PIX_FMT_YUV422P10 PIX_FMT_YUV422P10
+#define AV_PIX_FMT_YUV444P PIX_FMT_YUV444P
+#define AV_PIX_FMT_YUV444P10 PIX_FMT_YUV444P10
+#define AV_PIX_FMT_YUVJ420P PIX_FMT_YUVJ420P
+#define AV_PIX_FMT_YUVJ422P PIX_FMT_YUVJ422P
+#define AV_PIX_FMT_YUVJ444P PIX_FMT_YUVJ444P
+#endif
+
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(54, 25, 0)
+#define AV_CODEC_ID_TEXT CODEC_ID_TEXT
+#endif
 
 // The read thread.
 // This thread reads packets from the AVFormatContext and stores them in the
@@ -150,7 +167,8 @@ public:
 // Hide the FFmpeg stuff so that their messy header files cannot cause problems
 // in other source files.
 
-static const size_t audio_tmpbuf_size = (AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2;
+static const size_t max_audio_frame_size = 19200; // 1 second of 48khz 32bit audio
+static const size_t audio_tmpbuf_size = (max_audio_frame_size * 3) / 2;
 
 struct ffmpeg_stuff
 {
@@ -422,20 +440,20 @@ void media_object::set_video_frame_templ
     video_frame_template.value_range = video_frame::u8_full;
     video_frame_template.chroma_location = video_frame::center;
     if (!_always_convert_to_bgra32
-            && (video_codec_ctx->pix_fmt == PIX_FMT_YUV444P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV444P10
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV422P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV422P10
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV420P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV420P10))
+            && (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV444P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV444P10
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV422P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV422P10
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV420P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV420P10))
     {
-        if (video_codec_ctx->pix_fmt == PIX_FMT_YUV444P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV444P10)
+        if (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV444P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV444P10)
         {
             video_frame_template.layout = video_frame::yuv444p;
         }
-        else if (video_codec_ctx->pix_fmt == PIX_FMT_YUV422P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV422P10)
+        else if (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV422P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV422P10)
         {
             video_frame_template.layout = video_frame::yuv422p;
         }
@@ -448,9 +466,9 @@ void media_object::set_video_frame_templ
         {
             video_frame_template.color_space = video_frame::yuv709;
         }
-        if (video_codec_ctx->pix_fmt == PIX_FMT_YUV444P10
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV422P10
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUV420P10)
+        if (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV444P10
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV422P10
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUV420P10)
         {
             video_frame_template.value_range = video_frame::u10_mpeg;
             if (video_codec_ctx->color_range == AVCOL_RANGE_JPEG)
@@ -477,15 +495,15 @@ void media_object::set_video_frame_templ
         }
     }
     else if (!_always_convert_to_bgra32
-            && (video_codec_ctx->pix_fmt == PIX_FMT_YUVJ444P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUVJ422P
-                || video_codec_ctx->pix_fmt == PIX_FMT_YUVJ420P))
+            && (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUVJ444P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUVJ422P
+                || video_codec_ctx->pix_fmt == AV_PIX_FMT_YUVJ420P))
     {
-        if (video_codec_ctx->pix_fmt == PIX_FMT_YUVJ444P)
+        if (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUVJ444P)
         {
             video_frame_template.layout = video_frame::yuv444p;
         }
-        else if (video_codec_ctx->pix_fmt == PIX_FMT_YUVJ422P)
+        else if (video_codec_ctx->pix_fmt == AV_PIX_FMT_YUVJ422P)
         {
             video_frame_template.layout = video_frame::yuv422p;
         }
@@ -879,7 +897,7 @@ void media_object::open(const std::strin
     {
         _ffmpeg->format_ctx->streams[i]->discard = AVDISCARD_ALL;        // ignore by default; user must activate streams
         AVCodecContext *codec_ctx = _ffmpeg->format_ctx->streams[i]->codec;
-        AVCodec *codec = (codec_ctx->codec_id == CODEC_ID_TEXT
+        AVCodec *codec = (codec_ctx->codec_id == AV_CODEC_ID_TEXT
                 ? NULL : avcodec_find_decoder(codec_ctx->codec_id));
         // XXX: Sometimes the reported width and height for a video stream change after avcodec_open(),
         // but the original values seem to be correct. This seems to happen mostly with 1920x1080 video
@@ -899,8 +917,8 @@ void media_object::open(const std::strin
             if (codec_ctx->lowres || (codec && (codec->capabilities & CODEC_CAP_DR1)))
                 codec_ctx->flags |= CODEC_FLAG_EMU_EDGE;
         }
-        // Find and open the codec. CODEC_ID_TEXT is a special case: it has no decoder since it is unencoded raw data.
-        if (codec_ctx->codec_id != CODEC_ID_TEXT && (!codec || (e = avcodec_open2(codec_ctx, codec, NULL)) < 0))
+        // Find and open the codec. AV_CODEC_ID_TEXT is a special case: it has no decoder since it is unencoded raw data.
+        if (codec_ctx->codec_id != AV_CODEC_ID_TEXT && (!codec || (e = avcodec_open2(codec_ctx, codec, NULL)) < 0))
         {
             msg::wrn(_("%s stream %d: Cannot open %s: %s"), _url.c_str(), i,
                     codec_ctx->codec_type == AVMEDIA_TYPE_VIDEO ? _("video codec")
@@ -928,10 +946,15 @@ void media_object::open(const std::strin
             _ffmpeg->video_packets.push_back(AVPacket());
             av_init_packet(&(_ffmpeg->video_packets[j]));
             _ffmpeg->video_decode_threads.push_back(video_decode_thread(_url, _ffmpeg, j));
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(55, 28, 1)
             _ffmpeg->video_frames.push_back(avcodec_alloc_frame());
             _ffmpeg->video_buffered_frames.push_back(avcodec_alloc_frame());
-            enum PixelFormat frame_fmt = (_ffmpeg->video_frame_templates[j].layout == video_frame::bgra32
-                    ? PIX_FMT_BGRA : _ffmpeg->video_codec_ctxs[j]->pix_fmt);
+#else
+            _ffmpeg->video_frames.push_back(av_frame_alloc());
+            _ffmpeg->video_buffered_frames.push_back(av_frame_alloc());
+#endif
+            enum AVPixelFormat frame_fmt = (_ffmpeg->video_frame_templates[j].layout == video_frame::bgra32
+                    ? AV_PIX_FMT_BGRA : _ffmpeg->video_codec_ctxs[j]->pix_fmt);
             int frame_bufsize = (avpicture_get_size(frame_fmt,
                         _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height));
             _ffmpeg->video_buffers.push_back(static_cast<uint8_t *>(av_malloc(frame_bufsize)));
@@ -944,20 +967,24 @@ void media_object::open(const std::strin
             if (_ffmpeg->video_frame_templates[j].layout == video_frame::bgra32)
             {
                 // Initialize things needed for software pixel format conversion
-                int sws_bufsize = avpicture_get_size(PIX_FMT_BGRA,
+                int sws_bufsize = avpicture_get_size(AV_PIX_FMT_BGRA,
                         _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height);
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(55, 28, 1)
                 _ffmpeg->video_sws_frames.push_back(avcodec_alloc_frame());
+#else
+                _ffmpeg->video_sws_frames.push_back(av_frame_alloc());
+#endif
                 _ffmpeg->video_sws_buffers.push_back(static_cast<uint8_t *>(av_malloc(sws_bufsize)));
                 if (!_ffmpeg->video_sws_frames[j] || !_ffmpeg->video_sws_buffers[j])
                 {
                     throw exc(HERE + ": " + strerror(ENOMEM));
                 }
                 avpicture_fill(reinterpret_cast<AVPicture *>(_ffmpeg->video_sws_frames[j]), _ffmpeg->video_sws_buffers[j],
-                        PIX_FMT_BGRA, _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height);
+                        AV_PIX_FMT_BGRA, _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height);
                 // Call sws_getCachedContext(NULL, ...) instead of sws_getContext(...) just to avoid a deprecation warning.
                 _ffmpeg->video_sws_ctxs.push_back(sws_getCachedContext(NULL,
                             _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height, _ffmpeg->video_codec_ctxs[j]->pix_fmt,
-                            _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height, PIX_FMT_BGRA,
+                            _ffmpeg->video_codec_ctxs[j]->width, _ffmpeg->video_codec_ctxs[j]->height, AV_PIX_FMT_BGRA,
                             SWS_POINT, NULL, NULL, NULL));
                 if (!_ffmpeg->video_sws_ctxs[j])
                 {
@@ -1000,9 +1027,9 @@ void media_object::open(const std::strin
             int j = _ffmpeg->subtitle_streams.size() - 1;
             msg::dbg(_url + " stream " + str::from(i) + " is subtitle stream " + str::from(j) + ".");
             _ffmpeg->subtitle_codec_ctxs.push_back(codec_ctx);
-            // CODEC_ID_TEXT does not have any decoder; it is just UTF-8 text in the packet data.
+            // AV_CODEC_ID_TEXT does not have any decoder; it is just UTF-8 text in the packet data.
             _ffmpeg->subtitle_codecs.push_back(
-                    _ffmpeg->subtitle_codec_ctxs[j]->codec_id == CODEC_ID_TEXT ? NULL : codec);
+                    _ffmpeg->subtitle_codec_ctxs[j]->codec_id == AV_CODEC_ID_TEXT ? NULL : codec);
             _ffmpeg->subtitle_box_templates.push_back(subtitle_box());
             set_subtitle_box_template(j);
             _ffmpeg->subtitle_decode_threads.push_back(subtitle_decode_thread(_url, _ffmpeg, j));
@@ -1505,7 +1532,7 @@ read_frame:
                 // We need to buffer the data because FFmpeg will clubber it when decoding the next frame.
                 av_picture_copy(reinterpret_cast<AVPicture *>(_ffmpeg->video_buffered_frames[_video_stream]),
                         reinterpret_cast<AVPicture *>(_ffmpeg->video_frames[_video_stream]),
-                        static_cast<enum PixelFormat>(_ffmpeg->video_codec_ctxs[_video_stream]->pix_fmt),
+                        static_cast<enum AVPixelFormat>(_ffmpeg->video_codec_ctxs[_video_stream]->pix_fmt),
                         _ffmpeg->video_codec_ctxs[_video_stream]->width,
                         _ffmpeg->video_codec_ctxs[_video_stream]->height);
                 src_frame = _ffmpeg->video_buffered_frames[_video_stream];
@@ -1776,8 +1803,8 @@ void subtitle_decode_thread::run()
         int got_subtitle;
         tmppacket = packet;
 
-        // CODEC_ID_TEXT does not have any decoder; it is just UTF-8 text in the packet data.
-        if (_ffmpeg->subtitle_codec_ctxs[_subtitle_stream]->codec_id == CODEC_ID_TEXT)
+        // AV_CODEC_ID_TEXT does not have any decoder; it is just UTF-8 text in the packet data.
+        if (_ffmpeg->subtitle_codec_ctxs[_subtitle_stream]->codec_id == AV_CODEC_ID_TEXT)
         {
             int64_t duration = packet.convergence_duration * 1000000
                 * _ffmpeg->format_ctx->streams[_ffmpeg->subtitle_streams[_subtitle_stream]]->time_base.num
@@ -1937,9 +1964,9 @@ void media_object::seek(int64_t dest_pos
     }
     for (size_t i = 0; i < _ffmpeg->subtitle_streams.size(); i++)
     {
-        if (_ffmpeg->format_ctx->streams[_ffmpeg->subtitle_streams[i]]->codec->codec_id != CODEC_ID_TEXT)
+        if (_ffmpeg->format_ctx->streams[_ffmpeg->subtitle_streams[i]]->codec->codec_id != AV_CODEC_ID_TEXT)
         {
-            // CODEC_ID_TEXT has no decoder, so we cannot flush its buffers
+            // AV_CODEC_ID_TEXT has no decoder, so we cannot flush its buffers
             avcodec_flush_buffers(_ffmpeg->format_ctx->streams[_ffmpeg->subtitle_streams[i]]->codec);
         }
         _ffmpeg->subtitle_box_buffers[i].clear();
