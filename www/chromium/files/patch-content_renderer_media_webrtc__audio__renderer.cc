--- content/renderer/media/webrtc_audio_renderer.cc.orig	2016-06-08 12:04:14.328279000 -0400
+++ content/renderer/media/webrtc_audio_renderer.cc	2016-06-08 12:04:28.210758000 -0400
@@ -162,7 +162,7 @@
   // Windows below.
   int frames_per_buffer = hardware_buffer_size;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // On Linux and MacOS, the low level IO implementations on the browser side
   // supports all buffer size the clients want. We use the native peer
   // connection buffer size (10ms) to achieve best possible performance.
