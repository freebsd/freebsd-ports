--- src/3rdparty/chromium/third_party/webrtc/base/stringutils.h.orig	2017-01-26 00:50:17 UTC
+++ src/3rdparty/chromium/third_party/webrtc/base/stringutils.h
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
