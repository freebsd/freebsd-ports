--- src/webrtc/src/rtc_base/byte_order.h.orig	2023-02-08 09:03:45 UTC
+++ src/webrtc/src/rtc_base/byte_order.h
@@ -90,6 +90,8 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 
+#elif defined(WEBRTC_BSD)
+#include <sys/endian.h>
 #elif defined(WEBRTC_POSIX)
 #include <endian.h>
 #else
