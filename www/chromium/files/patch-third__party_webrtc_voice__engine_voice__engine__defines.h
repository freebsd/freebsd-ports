--- third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2016-05-11 19:04:03 UTC
+++ third_party/webrtc/voice_engine/voice_engine_defines.h
@@ -210,7 +210,7 @@ inline int VoEChannelId(int moduleId) {
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
 #include <linux/net.h>
 #ifndef ANDROID
 #include <sys/soundcard.h>
