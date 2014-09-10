--- ./third_party/webrtc/base/stringutils.h.orig	2014-08-20 21:04:28.000000000 +0200
+++ ./third_party/webrtc/base/stringutils.h	2014-08-22 18:44:28.000000000 +0200
@@ -23,11 +23,11 @@
 #endif  // WEBRTC_WIN 
 
 #if defined(WEBRTC_POSIX)
-#ifdef BSD
+#ifdef WEBRTC_BSD
 #include <stdlib.h>
-#else  // BSD
+#else  // WEBRTC_BSD
 #include <alloca.h>
-#endif  // !BSD
+#endif  // !WEBRTC_BSD
 #endif  // WEBRTC_POSIX
 
 #include <string>
