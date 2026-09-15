-- Fix build with FFmpeg 9 (libavcodec 61+) where AVCodec::pix_fmts and
-- AVCodec::sample_fmts are no longer directly accessible. Use the new
-- avcodec_get_supported_config() API instead.
-- See: https://github.com/olive-editor/olive/issues/2387

--- app/codec/ffmpeg/ffmpegencoder.cpp.orig
+++ app/codec/ffmpeg/ffmpegencoder.cpp
@@ -55,6 +55,22 @@ QStringList FFmpegEncoder::GetPixelFormatsForCodec(ExportCodec::Codec c) const
   const AVCodec* codec_info = GetEncoder(c, SampleFormat::INVALID);

   if (codec_info) {
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 13, 100)
+    const AVPixelFormat* supported_pix_fmts = nullptr;
+    if (avcodec_get_supported_config(nullptr, codec_info, AV_CODEC_CONFIG_PIX_FORMAT, 0,
+                                     reinterpret_cast<const void**>(&supported_pix_fmts), nullptr) >= 0
+        && supported_pix_fmts) {
+      for (int i=0; supported_pix_fmts[i]!=AV_PIX_FMT_NONE; i++) {
+        if (FFmpegUtils::ConvertJPEGSpaceToRegularSpace(supported_pix_fmts[i]) != supported_pix_fmts[i]) {
+          // This is a deprecated "JPEG" space, skip it
+          continue;
+        }
+
+        const char* pix_fmt_name = av_get_pix_fmt_name(supported_pix_fmts[i]);
+        pix_fmts.append(pix_fmt_name);
+      }
+    }
+#else
     for (int i=0; codec_info->pix_fmts[i]!=-1; i++) {
       if (FFmpegUtils::ConvertJPEGSpaceToRegularSpace(codec_info->pix_fmts[i]) != codec_info->pix_fmts[i]) {
         // This is a deprecated "JPEG" space, skip it
@@ -64,6 +80,7 @@ QStringList FFmpegEncoder::GetPixelFormatsForCodec(ExportCodec::Codec c) const
       const char* pix_fmt_name = av_get_pix_fmt_name(codec_info->pix_fmts[i]);
       pix_fmts.append(pix_fmt_name);
     }
+#endif
   }

   return pix_fmts;
@@ -88,6 +105,21 @@ std::vector<SampleFormat> FFmpegEncoder::GetSampleFormatsForCodec(ExportCodec::Co
   } else {
     const AVCodec* codec_info = GetEncoder(c, SampleFormat::INVALID);

+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 13, 100)
+    if (codec_info) {
+      const AVSampleFormat* supported_sample_fmts = nullptr;
+      if (avcodec_get_supported_config(nullptr, codec_info, AV_CODEC_CONFIG_SAMPLE_FORMAT, 0,
+                                       reinterpret_cast<const void**>(&supported_sample_fmts), nullptr) >= 0
+          && supported_sample_fmts) {
+        for (int i=0; supported_sample_fmts[i]!=AV_SAMPLE_FMT_NONE; i++) {
+          SampleFormat this_format = FFmpegUtils::GetNativeSampleFormat(supported_sample_fmts[i]);
+          if (this_format != SampleFormat::INVALID) {
+            f.push_back(this_format);
+          }
+        }
+      }
+    }
+#else
     if (codec_info && codec_info->sample_fmts) {
       for (int i=0; codec_info->sample_fmts[i]!=-1; i++) {
         SampleFormat this_format = FFmpegUtils::GetNativeSampleFormat(static_cast<AVSampleFormat>(codec_info->sample_fmts[i]));
@@ -96,6 +128,7 @@ std::vector<SampleFormat> FFmpegEncoder::GetSampleFormatsForCodec(ExportCodec::Co
         }
       }
     }
+#endif
   }

   return f;
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
 
