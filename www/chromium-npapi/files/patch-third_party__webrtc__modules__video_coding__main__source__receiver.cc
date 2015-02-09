--- third_party/webrtc/modules/video_coding/main/source/receiver.cc.orig	2014-05-14 21:24:36.000000000 +0200
+++ third_party/webrtc/modules/video_coding/main/source/receiver.cc	2014-05-21 23:46:49.000000000 +0200
@@ -158,12 +158,12 @@
   // Assume that render timing errors are due to changes in the video stream.
   if (next_render_time_ms < 0) {
     timing_error = true;
-  } else if (std::abs(next_render_time_ms - now_ms) > max_video_delay_ms_) {
+  } else if (std::labs(next_render_time_ms - now_ms) > max_video_delay_ms_) {
     WEBRTC_TRACE(webrtc::kTraceWarning, webrtc::kTraceVideoCoding,
                  VCMId(vcm_id_, receiver_id_),
                  "This frame is out of our delay bounds, resetting jitter "
                  "buffer: %d > %d",
-                 static_cast<int>(std::abs(next_render_time_ms - now_ms)),
+                 static_cast<int>(std::labs(next_render_time_ms - now_ms)),
                  max_video_delay_ms_);
     timing_error = true;
   } else if (static_cast<int>(timing_->TargetVideoDelay()) >
