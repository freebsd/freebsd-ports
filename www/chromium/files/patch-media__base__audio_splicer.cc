--- ./media/base/audio_splicer.cc.orig	2014-04-24 22:35:18.000000000 +0200
+++ ./media/base/audio_splicer.cc	2014-04-24 23:23:46.000000000 +0200
@@ -60,7 +60,7 @@
   base::TimeDelta expected_timestamp = output_timestamp_helper_.GetTimestamp();
   base::TimeDelta delta = timestamp - expected_timestamp;
 
-  if (std::abs(delta.InMilliseconds()) > kMaxTimeDeltaInMilliseconds) {
+  if (std::labs(delta.InMilliseconds()) > kMaxTimeDeltaInMilliseconds) {
     DVLOG(1) << "Timestamp delta too large: " << delta.InMicroseconds() << "us";
     return false;
   }
@@ -69,7 +69,7 @@
   if (delta != base::TimeDelta())
     frames_to_fill = output_timestamp_helper_.GetFramesToTarget(timestamp);
 
-  if (frames_to_fill == 0 || std::abs(frames_to_fill) < min_gap_size_) {
+  if (frames_to_fill == 0 || std::labs(frames_to_fill) < min_gap_size_) {
     AddOutputBuffer(input);
     return true;
   }
