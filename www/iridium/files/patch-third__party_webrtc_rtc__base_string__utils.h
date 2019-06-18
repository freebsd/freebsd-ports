--- third_party/webrtc/rtc_base/string_utils.h.orig	2019-03-11 22:08:16 UTC
+++ third_party/webrtc/rtc_base/string_utils.h
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
 
