--- Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/stringutils.h.orig	2018-11-23 01:03:16 UTC
+++ Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/stringutils.h
@@ -25,7 +25,7 @@
 #endif  // WEBRTC_WIN
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#ifdef __FreeBSD__
 #include <stdlib.h>
 #else  // BSD
 #include <alloca.h>
