--- ./media/base/audio_splicer.cc.orig	2014-08-12 21:02:57.000000000 +0200
+++ ./media/base/audio_splicer.cc	2014-08-13 09:56:57.000000000 +0200
@@ -143,7 +143,7 @@
       output_timestamp_helper_.GetTimestamp();
   const base::TimeDelta delta = timestamp - expected_timestamp;
 
-  if (std::abs(delta.InMilliseconds()) > kMaxTimeDeltaInMilliseconds) {
+  if (std::labs(delta.InMilliseconds()) > kMaxTimeDeltaInMilliseconds) {
     DVLOG(1) << "Timestamp delta too large: " << delta.InMicroseconds() << "us";
     return false;
   }
@@ -152,7 +152,7 @@
   if (delta != base::TimeDelta())
     frames_to_fill = output_timestamp_helper_.GetFramesToTarget(timestamp);
 
-  if (frames_to_fill == 0 || std::abs(frames_to_fill) < kMinGapSize) {
+  if (frames_to_fill == 0 || std::labs(frames_to_fill) < kMinGapSize) {
     AddOutputBuffer(input);
     return true;
   }
