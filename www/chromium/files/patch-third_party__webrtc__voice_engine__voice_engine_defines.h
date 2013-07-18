--- third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2013-07-16 18:15:28.000000000 +0300
+++ third_party/webrtc/voice_engine/voice_engine_defines.h	2013-07-16 18:16:46.000000000 +0300
@@ -260,7 +260,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
   #include <linux/net.h>
 #ifndef ANDROID
   #include <sys/soundcard.h>
