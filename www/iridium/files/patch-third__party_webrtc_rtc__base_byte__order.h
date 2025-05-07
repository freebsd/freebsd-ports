--- third_party/webrtc/rtc_base/byte_order.h.orig	2025-05-07 06:48:23 UTC
+++ third_party/webrtc/rtc_base/byte_order.h
@@ -90,6 +90,8 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 
+#elif defined(WEBRTC_BSD)
+#include <sys/endian.h>
 #elif defined(WEBRTC_POSIX)
 #include <endian.h>
 #else
