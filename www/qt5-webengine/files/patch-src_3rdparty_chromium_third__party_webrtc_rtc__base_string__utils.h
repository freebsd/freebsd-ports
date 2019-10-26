--- src/3rdparty/chromium/third_party/webrtc/rtc_base/string_utils.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/string_utils.h
@@ -25,11 +25,11 @@
 #endif  // WEBRTC_WIN
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#if defined(WEBRTC_BSD) || defined(BSD)
 #include <stdlib.h>
-#else  // BSD
+#else  // WEBRTC_BSD
 #include <alloca.h>
-#endif  // !BSD
+#endif  // !WEBRTC_BSD
 #include <strings.h>
 #endif  // WEBRTC_POSIX
 
