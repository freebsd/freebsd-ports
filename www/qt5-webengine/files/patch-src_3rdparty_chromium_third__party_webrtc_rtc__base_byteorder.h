--- src/3rdparty/chromium/third_party/webrtc/rtc_base/byteorder.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/byteorder.h
@@ -79,7 +79,11 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 #elif defined(WEBRTC_POSIX)
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #endif
 
 namespace rtc {
