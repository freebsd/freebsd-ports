--- third_party/webrtc/rtc_base/stringutils.h.orig	2019-01-30 02:20:38.000000000 +0100
+++ third_party/webrtc/rtc_base/stringutils.h	2019-02-01 16:59:24.656841000 +0100
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
 
