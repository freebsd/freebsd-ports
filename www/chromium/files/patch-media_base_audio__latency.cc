--- media/base/audio_latency.cc.orig	2017-12-15 02:04:21.000000000 +0100
+++ media/base/audio_latency.cc	2017-12-24 17:08:13.779303000 +0100
@@ -106,7 +106,7 @@
     return frames_per_buffer;
   }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
   // peer connection buffer size (10ms) to achieve best possible performance.
