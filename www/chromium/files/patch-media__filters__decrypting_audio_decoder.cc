--- media/filters/decrypting_audio_decoder.cc.orig	2013-08-30 06:47:05.000000000 +0300
+++ media/filters/decrypting_audio_decoder.cc	2013-09-03 22:11:24.289626887 +0300
@@ -30,7 +30,7 @@
   // Out of sync of 100ms would be pretty noticeable and we should keep any
   // drift below that.
   const int64 kOutOfSyncThresholdInMilliseconds = 100;
-  return std::abs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
+  return std::labs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
          kOutOfSyncThresholdInMilliseconds;
 }
 
