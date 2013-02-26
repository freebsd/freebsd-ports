--- media/base/audio_splicer.cc.orig	2013-02-21 04:24:13.000000000 +0100
+++ media/base/audio_splicer.cc	2013-02-26 12:33:35.000000000 +0100
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
     bytes_to_fill = output_timestamp_helper_.GetBytesToTarget(timestamp);
 
-  if (bytes_to_fill == 0 || std::abs(bytes_to_fill) < min_gap_size_) {
+  if (bytes_to_fill == 0 || std::labs(bytes_to_fill) < min_gap_size_) {
     AddOutputBuffer(input);
     return true;
   }
