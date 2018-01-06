--- src/3rdparty/chromium/third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2017-01-26 00:50:17 UTC
+++ src/3rdparty/chromium/third_party/webrtc/voice_engine/voice_engine_defines.h
@@ -210,7 +210,7 @@ inline int VoEChannelId(int moduleId) {
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
 #include <linux/net.h>
 #ifndef ANDROID
 #include <sys/soundcard.h>
