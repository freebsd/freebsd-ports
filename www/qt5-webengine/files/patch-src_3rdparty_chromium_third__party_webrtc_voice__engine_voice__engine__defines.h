--- src/3rdparty/chromium/third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/third_party/webrtc/voice_engine/voice_engine_defines.h
@@ -203,19 +203,21 @@ inline int VoEChannelId(int moduleId) {
 
 // *** LINUX ***
 
-#ifdef WEBRTC_LINUX
+#if defined(WEBRTC_LINUX) || defined(BSD)
 
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#ifndef BSD
 #ifndef QNX
 #include <linux/net.h>
 #ifndef ANDROID
 #include <sys/soundcard.h>
 #endif  // ANDROID
 #endif  // QNX
+#endif  // BSD
 #include <errno.h>
 #include <fcntl.h>
 #include <sched.h>
