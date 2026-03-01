--- app/codec/ffmpeg/ffmpegdecoder.cpp.orig	2024-12-04 17:13:33 UTC
+++ app/codec/ffmpeg/ffmpegdecoder.cpp
@@ -355,8 +355,15 @@ FootageDescription FFmpegDecoder::Probe(const QString 
               // Read first frame and retrieve some metadata
               if (instance.GetFrame(pkt, frame) >= 0) {
                 // Check if video is interlaced and what field dominance it has if so
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(58, 0, 100)
+                int interlaced = (frame->flags & AV_FRAME_FLAG_INTERLACED);
+                int top_field_first = (frame->flags & AV_FRAME_FLAG_TOP_FIELD_FIRST);
+                if (interlaced) {
+                  if (top_field_first) {
+#else
                 if (frame->interlaced_frame) {
                   if (frame->top_field_first) {
+#endif
                     interlacing = VideoParams::kInterlacedTopFirst;
                   } else {
                     interlacing = VideoParams::kInterlacedBottomFirst;
@@ -439,10 +446,30 @@ FootageDescription FFmpegDecoder::Probe(const QString 
         } else if (avstream->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
 
           // Create an audio stream object
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+          uint64_t channel_layout;
+          if (avstream->codecpar->ch_layout.order != AV_CHANNEL_ORDER_UNSPEC) {
+            AVChannelLayout ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+            av_channel_layout_copy(&ch_layout, &avstream->codecpar->ch_layout);
+            if (ch_layout.order == AV_CHANNEL_ORDER_NATIVE && ch_layout.u.mask) {
+              channel_layout = ch_layout.u.mask;
+            } else {
+              av_channel_layout_default(&ch_layout, avstream->codecpar->ch_layout.nb_channels);
+              channel_layout = ch_layout.u.mask;
+            }
+            av_channel_layout_uninit(&ch_layout);
+          } else {
+            AVChannelLayout ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+            av_channel_layout_default(&ch_layout, avstream->codecpar->ch_layout.nb_channels);
+            channel_layout = ch_layout.u.mask;
+            av_channel_layout_uninit(&ch_layout);
+          }
+#else
           uint64_t channel_layout = avstream->codecpar->channel_layout;
           if (!channel_layout) {
             channel_layout = static_cast<uint64_t>(av_get_default_channel_layout(avstream->codecpar->channels));
           }
+#endif
 
           if (avstream->duration == AV_NOPTS_VALUE || duration_guessed_from_bitrate) {
             // Loop through stream until we get the whole duration
@@ -558,6 +585,29 @@ bool FFmpegDecoder::ConformAudioInternal(const QVector
   }
 
   // Create resampling context
+#if LIBSWRESAMPLE_VERSION_INT >= AV_VERSION_INT(4, 5, 100)
+  AVChannelLayout out_ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+  AVChannelLayout in_ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+  av_channel_layout_from_mask(&out_ch_layout, params.channel_layout());
+  av_channel_layout_from_mask(&in_ch_layout, channel_layout);
+  
+  SwrContext* resampler = nullptr;
+  int swr_ret = swr_alloc_set_opts2(&resampler,
+                                    &out_ch_layout,
+                                    FFmpegUtils::GetFFmpegSampleFormat(params.format()),
+                                    params.sample_rate(),
+                                    &in_ch_layout,
+                                    static_cast<AVSampleFormat>(instance_.avstream()->codecpar->format),
+                                    instance_.avstream()->codecpar->sample_rate,
+                                    0,
+                                    nullptr);
+  av_channel_layout_uninit(&out_ch_layout);
+  av_channel_layout_uninit(&in_ch_layout);
+  
+  if (swr_ret < 0) {
+    return false;
+  }
+#else
   SwrContext* resampler = swr_alloc_set_opts(nullptr,
                                              params.channel_layout(),
                                              FFmpegUtils::GetFFmpegSampleFormat(params.format()),
@@ -567,6 +617,7 @@ bool FFmpegDecoder::ConformAudioInternal(const QVector
                                              instance_.avstream()->codecpar->sample_rate,
                                              0,
                                              nullptr);
+#endif
 
   swr_init(resampler);
 
@@ -691,11 +742,35 @@ uint64_t FFmpegDecoder::ValidateChannelLayout(AVStream
 
 uint64_t FFmpegDecoder::ValidateChannelLayout(AVStream* stream)
 {
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+  if (stream->codecpar->ch_layout.order != AV_CHANNEL_ORDER_UNSPEC) {
+    AVChannelLayout ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+    av_channel_layout_copy(&ch_layout, &stream->codecpar->ch_layout);
+    uint64_t mask = 0;
+    if (ch_layout.order == AV_CHANNEL_ORDER_NATIVE && ch_layout.u.mask) {
+      mask = ch_layout.u.mask;
+    } else {
+      AVChannelLayout default_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+      av_channel_layout_default(&default_layout, stream->codecpar->ch_layout.nb_channels);
+      mask = default_layout.u.mask;
+      av_channel_layout_uninit(&default_layout);
+    }
+    av_channel_layout_uninit(&ch_layout);
+    return mask;
+  }
+
+  AVChannelLayout ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+  av_channel_layout_default(&ch_layout, stream->codecpar->ch_layout.nb_channels);
+  uint64_t mask = ch_layout.u.mask;
+  av_channel_layout_uninit(&ch_layout);
+  return mask;
+#else
   if (stream->codecpar->channel_layout) {
     return stream->codecpar->channel_layout;
   }
 
   return av_get_default_channel_layout(stream->codecpar->channels);
+#endif
 }
 
 const char *FFmpegDecoder::GetInterlacingModeInFFmpeg(VideoParams::Interlacing interlacing)
