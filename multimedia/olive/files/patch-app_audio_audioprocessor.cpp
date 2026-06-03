--- app/audio/audioprocessor.cpp.orig	2026-02-28 23:14:00 UTC
+++ app/audio/audioprocessor.cpp
@@ -169,8 +169,12 @@ bool AudioProcessor::Open(const AudioParams &from, con
   if (in_frame_) {
     in_frame_->sample_rate = from.sample_rate();
     in_frame_->format = from_fmt_;
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57, 28, 100)
+    av_channel_layout_from_mask(&in_frame_->ch_layout, from.channel_layout());
+#else
     in_frame_->channel_layout = from.channel_layout();
     in_frame_->channels = from.channel_count();
+#endif
     in_frame_->pts = 0;
   } else {
     qCritical() << "Failed to allocate input frame";
