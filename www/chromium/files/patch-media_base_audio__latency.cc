--- media/base/audio_latency.cc.orig	2022-02-07 13:39:41 UTC
+++ media/base/audio_latency.cc
@@ -135,7 +135,7 @@ int AudioLatency::GetRtcBufferSize(int sample_rate, in
   }
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
   // peer connection buffer size (10ms) to achieve best possible performance.
