--- media/ffmpeg/ffmpeg_common.cc.orig	2018-04-28 17:44:34.207381000 +0200
+++ media/ffmpeg/ffmpeg_common.cc	2018-04-28 17:46:24.946243000 +0200
@@ -33,7 +33,7 @@
 // Why FF_INPUT_BUFFER_PADDING_SIZE? FFmpeg assumes all input buffers are
 // padded. Check here to ensure FFmpeg only receives data padded to its
 // specifications.
-static_assert(DecoderBuffer::kPaddingSize >= FF_INPUT_BUFFER_PADDING_SIZE,
+static_assert(DecoderBuffer::kPaddingSize >= AV_INPUT_BUFFER_PADDING_SIZE,
               "DecoderBuffer padding size does not fit ffmpeg requirement");
 
 // Alignment requirement by FFmpeg for input and output buffers. This need to
@@ -429,11 +429,11 @@
   } else {
     codec_context->extradata_size = config.extra_data().size();
     codec_context->extradata = reinterpret_cast<uint8_t*>(
-        av_malloc(config.extra_data().size() + FF_INPUT_BUFFER_PADDING_SIZE));
+        av_malloc(config.extra_data().size() + AV_INPUT_BUFFER_PADDING_SIZE));
     memcpy(codec_context->extradata, &config.extra_data()[0],
            config.extra_data().size());
     memset(codec_context->extradata + config.extra_data().size(), '\0',
-           FF_INPUT_BUFFER_PADDING_SIZE);
+           AV_INPUT_BUFFER_PADDING_SIZE);
   }
 }
 
@@ -561,11 +561,11 @@
   } else {
     codec_context->extradata_size = config.extra_data().size();
     codec_context->extradata = reinterpret_cast<uint8_t*>(
-        av_malloc(config.extra_data().size() + FF_INPUT_BUFFER_PADDING_SIZE));
+        av_malloc(config.extra_data().size() + AV_INPUT_BUFFER_PADDING_SIZE));
     memcpy(codec_context->extradata, &config.extra_data()[0],
            config.extra_data().size());
     memset(codec_context->extradata + config.extra_data().size(), '\0',
-           FF_INPUT_BUFFER_PADDING_SIZE);
+           AV_INPUT_BUFFER_PADDING_SIZE);
   }
 }
 
