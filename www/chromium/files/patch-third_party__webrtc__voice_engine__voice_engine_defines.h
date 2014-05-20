--- ./third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2014-04-30 22:44:26.000000000 +0200
+++ ./third_party/webrtc/voice_engine/voice_engine_defines.h	2014-05-04 14:38:49.000000000 +0200
@@ -233,7 +233,7 @@
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
   #include <linux/net.h>
 #ifndef ANDROID
   #include <sys/soundcard.h>
