--- app/codec/ffmpeg/ffmpegencoder.cpp.orig	2024-12-04 17:13:33 UTC
+++ app/codec/ffmpeg/ffmpegencoder.cpp
@@ -334,7 +334,11 @@ bool FFmpegEncoder::WriteAudioData(const AudioParams &
   int output_sample_count = input_sample_count ? swr_get_out_samples(audio_resample_ctx_, input_sample_count) : 102400;
   uint8_t** output_data = nullptr;
   int output_linesize;
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+  av_samples_alloc_array_and_samples(&output_data, &output_linesize, audio_stream_->codecpar->ch_layout.nb_channels,
+#else
   av_samples_alloc_array_and_samples(&output_data, &output_linesize, audio_stream_->codecpar->channels,
+#endif
                                      output_sample_count, static_cast<AVSampleFormat>(audio_stream_->codecpar->format), 0);
 
   // Perform conversion
@@ -349,7 +353,11 @@ bool FFmpegEncoder::WriteAudioData(const AudioParams &
 
       av_samples_copy(audio_frame_->data, output_data, audio_frame_offset_, i,
                       copy_length,
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+                      audio_frame_->ch_layout.nb_channels, static_cast<AVSampleFormat>(audio_frame_->format));
+#else
                       audio_frame_->channels, static_cast<AVSampleFormat>(audio_frame_->format));
+#endif
 
       audio_frame_offset_ += copy_length;
       i += copy_length;
@@ -690,8 +698,12 @@ bool FFmpegEncoder::InitializeStream(AVMediaType type,
 
     // Assume audio stream
     codec_ctx->sample_rate = params().audio_params().sample_rate();
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+    av_channel_layout_from_mask(&codec_ctx->ch_layout, params().audio_params().channel_layout());
+#else
     codec_ctx->channel_layout = params().audio_params().channel_layout();
     codec_ctx->channels = av_get_channel_layout_nb_channels(codec_ctx->channel_layout);
+#endif
     codec_ctx->sample_fmt = FFmpegUtils::GetFFmpegSampleFormat(params().audio_params().format());
     codec_ctx->time_base = {1, codec_ctx->sample_rate};
 
@@ -787,12 +799,19 @@ void FFmpegEncoder::FlushEncoders()
   }
 
   if (fmt_ctx_) {
+#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(59, 0, 100)
+    // AVFMT_ALLOW_FLUSH removed in ffmpeg 7+, always allow flush now
+    int r = av_interleaved_write_frame(fmt_ctx_, nullptr);
+#else
     if (fmt_ctx_->oformat->flags & AVFMT_ALLOW_FLUSH) {
       int r = av_interleaved_write_frame(fmt_ctx_, nullptr);
+#endif
       if (r < 0) {
         FFmpegError(tr("Failed to write interleaved packet"), r);
       }
+#if LIBAVFORMAT_VERSION_INT < AV_VERSION_INT(59, 0, 100)
     }
+#endif
   }
 }
 
@@ -829,6 +848,28 @@ bool FFmpegEncoder::InitializeResampleContext(const Au
   }
 
   // Create resample context
+#if LIBSWRESAMPLE_VERSION_INT >= AV_VERSION_INT(4, 5, 100)
+  AVChannelLayout out_ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+  AVChannelLayout in_ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+  av_channel_layout_from_mask(&out_ch_layout, audio_codec_ctx_->ch_layout.u.mask ? audio_codec_ctx_->ch_layout.u.mask : AV_CH_LAYOUT_STEREO);
+  av_channel_layout_from_mask(&in_ch_layout, audio.channel_layout());
+  
+  int ret = swr_alloc_set_opts2(&audio_resample_ctx_,
+                                &out_ch_layout,
+                                audio_codec_ctx_->sample_fmt,
+                                audio_codec_ctx_->sample_rate,
+                                &in_ch_layout,
+                                FFmpegUtils::GetFFmpegSampleFormat(audio.format()),
+                                audio.sample_rate(),
+                                0,
+                                nullptr);
+  av_channel_layout_uninit(&out_ch_layout);
+  av_channel_layout_uninit(&in_ch_layout);
+  
+  if (ret < 0) {
+    return false;
+  }
+#else
   audio_resample_ctx_ = swr_alloc_set_opts(nullptr,
                                            static_cast<int64_t>(audio_codec_ctx_->channel_layout),
                                            audio_codec_ctx_->sample_fmt,
@@ -838,6 +879,7 @@ bool FFmpegEncoder::InitializeResampleContext(const Au
                                            audio.sample_rate(),
                                            0,
                                            nullptr);
+#endif
   if (!audio_resample_ctx_) {
     return false;
   }
@@ -865,7 +907,11 @@ bool FFmpegEncoder::InitializeResampleContext(const Au
     return false;
   }
 
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+  av_channel_layout_copy(&audio_frame_->ch_layout, &audio_codec_ctx_->ch_layout);
+#else
   audio_frame_->channel_layout = audio_codec_ctx_->channel_layout;
+#endif
   audio_frame_->format = audio_codec_ctx_->sample_fmt;
   audio_frame_->nb_samples = audio_max_samples_;
 
