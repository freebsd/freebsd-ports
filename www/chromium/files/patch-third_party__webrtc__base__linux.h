--- third_party/webrtc/base/linux.h.orig	2014-10-10 09:16:13 UTC
+++ third_party/webrtc/base/linux.h
@@ -11,7 +11,7 @@
 #ifndef WEBRTC_BASE_LINUX_H_
 #define WEBRTC_BASE_LINUX_H_
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include <string>
 #include <map>
 #include <vector>
@@ -119,5 +119,5 @@
 
 }  // namespace rtc
 
-#endif  // defined(WEBRTC_LINUX)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #endif  // WEBRTC_BASE_LINUX_H_
