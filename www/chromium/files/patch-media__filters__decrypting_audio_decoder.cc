--- media/filters/decrypting_audio_decoder.cc.orig	2013-01-07 18:40:10.000000000 -0800
+++ media/filters/decrypting_audio_decoder.cc	2013-01-12 09:05:12.737640582 -0800
@@ -30,7 +30,7 @@
   // Out of sync of 100ms would be pretty noticeable and we should keep any
   // drift below that.
   const int64 kOutOfSyncThresholdInMicroseconds = 100000;
-  return std::abs(timestamp_1.InMicroseconds() - timestamp_2.InMicroseconds()) >
+  return std::labs(timestamp_1.InMicroseconds() - timestamp_2.InMicroseconds()) >
          kOutOfSyncThresholdInMicroseconds;
 }
