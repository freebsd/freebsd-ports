--- media/base/audio_latency.cc.orig	2017-04-19 19:06:35 UTC
+++ media/base/audio_latency.cc
@@ -83,7 +83,7 @@ int AudioLatency::GetRtcBufferSize(int s
     return frames_per_buffer;
   }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // On Linux and MacOS, the low level IO implementations on the browser side
   // supports all buffer size the clients want. We use the native peer
   // connection buffer size (10ms) to achieve best possible performance.
