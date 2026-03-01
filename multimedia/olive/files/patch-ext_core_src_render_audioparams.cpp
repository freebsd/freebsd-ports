--- ext/core/src/render/audioparams.cpp.orig	2026-02-28 23:05:00 UTC
+++ ext/core/src/render/audioparams.cpp
@@ -159,7 +159,19 @@ void AudioParams::calculate_channel_count()
 
 void AudioParams::calculate_channel_count()
 {
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+  // ffmpeg 5.1+ uses new channel layout API
+  AVChannelLayout ch_layout = AV_CHANNEL_LAYOUT_MASK(0, 0);
+  if (channel_layout() > 0) {
+    av_channel_layout_from_mask(&ch_layout, channel_layout());
+    channel_count_ = ch_layout.nb_channels;
+    av_channel_layout_uninit(&ch_layout);
+  } else {
+    channel_count_ = 0;
+  }
+#else
   channel_count_ = av_get_channel_layout_nb_channels(channel_layout());
+#endif
 }
 
 }
