--- Telegram/ThirdParty/libtgvoip/webrtc_dsp/webrtc/base/stringutils.h.orig	2017-07-06 17:16:18 UTC
+++ Telegram/ThirdParty/libtgvoip/webrtc_dsp/webrtc/base/stringutils.h
@@ -23,7 +23,7 @@
 #endif  // WEBRTC_WIN 
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#if defined BSD || defined __FreeBSD__
 #include <stdlib.h>
 #else  // BSD
 #include <alloca.h>
