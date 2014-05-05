--- ./media/filters/decrypting_audio_decoder.cc.orig	2014-04-24 22:35:18.000000000 +0200
+++ ./media/filters/decrypting_audio_decoder.cc	2014-04-24 23:23:46.000000000 +0200
@@ -30,7 +30,7 @@
   // Out of sync of 100ms would be pretty noticeable and we should keep any
   // drift below that.
   const int64 kOutOfSyncThresholdInMilliseconds = 100;
-  return std::abs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
+  return std::labs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
          kOutOfSyncThresholdInMilliseconds;
 }
 
