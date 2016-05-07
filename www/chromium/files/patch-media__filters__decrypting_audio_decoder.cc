--- media/filters/decrypting_audio_decoder.cc.orig	2016-03-04 23:02:30.943530609 +0100
+++ media/filters/decrypting_audio_decoder.cc	2016-03-04 23:02:36.647530119 +0100
@@ -29,7 +29,7 @@
   // Out of sync of 100ms would be pretty noticeable and we should keep any
   // drift below that.
   const int64_t kOutOfSyncThresholdInMilliseconds = 100;
-  return std::abs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
+  return std::labs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
          kOutOfSyncThresholdInMilliseconds;
 }
 
