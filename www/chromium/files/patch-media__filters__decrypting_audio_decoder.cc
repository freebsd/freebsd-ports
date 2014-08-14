--- ./media/filters/decrypting_audio_decoder.cc.orig	2014-08-12 21:02:56.000000000 +0200
+++ ./media/filters/decrypting_audio_decoder.cc	2014-08-13 09:56:57.000000000 +0200
@@ -30,7 +30,7 @@
   // Out of sync of 100ms would be pretty noticeable and we should keep any
   // drift below that.
   const int64 kOutOfSyncThresholdInMilliseconds = 100;
-  return std::abs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
+  return std::labs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
          kOutOfSyncThresholdInMilliseconds;
 }
 
