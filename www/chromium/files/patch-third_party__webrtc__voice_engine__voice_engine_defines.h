--- third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2013-08-09 22:21:34.000000000 +0300
+++ third_party/webrtc/voice_engine/voice_engine_defines.h	2013-08-16 21:25:45.000000000 +0300
@@ -260,7 +260,7 @@
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
   #include <linux/net.h>
 #ifndef ANDROID
   #include <sys/soundcard.h>
