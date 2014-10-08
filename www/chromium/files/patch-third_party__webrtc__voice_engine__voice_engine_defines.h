--- third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2014-10-02 17:40:34 UTC
+++ third_party/webrtc/voice_engine/voice_engine_defines.h
@@ -237,7 +237,7 @@
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
   #include <linux/net.h>
 #ifndef ANDROID
   #include <sys/soundcard.h>
