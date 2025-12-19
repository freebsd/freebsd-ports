--- src/3rdparty/chromium/media/base/audio_latency.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/media/base/audio_latency.cc
@@ -148,7 +148,7 @@ int AudioLatency::GetRtcBufferSize(int sample_rate, in
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
   // peer connection buffer size (10ms) to achieve best possible performance.
