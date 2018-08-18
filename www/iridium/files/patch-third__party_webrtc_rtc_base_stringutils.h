--- third_party/webrtc/rtc_base/stringutils.h.orig	2017-09-07 00:56:34.723687000 +0200
+++ third_party/webrtc/rtc_base/stringutils.h	2017-09-07 01:34:35.259034000 +0200
@@ -23,11 +23,11 @@
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
 #endif  // WEBRTC_POSIX
 
 #include <string>
