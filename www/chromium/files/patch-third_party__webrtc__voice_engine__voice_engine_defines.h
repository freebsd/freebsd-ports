--- third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2015-07-15 16:32:13.000000000 -0400
+++ third_party/webrtc/voice_engine/voice_engine_defines.h	2015-07-22 18:28:32.539800000 -0400
@@ -213,7 +213,7 @@
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
 #include <linux/net.h>
 #ifndef ANDROID
 #include <sys/soundcard.h>
