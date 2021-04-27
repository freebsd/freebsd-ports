--- media/base/audio_latency.cc.orig	2021-04-14 18:41:05 UTC
+++ media/base/audio_latency.cc
@@ -134,7 +134,7 @@ int AudioLatency::GetRtcBufferSize(int sample_rate, in
     return frames_per_buffer;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
