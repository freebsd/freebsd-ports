--- third_party/webrtc/rtc_base/byte_order.h.orig	2019-03-11 22:08:15 UTC
+++ third_party/webrtc/rtc_base/byte_order.h
@@ -79,7 +79,7 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 #elif defined(WEBRTC_POSIX)
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 namespace rtc {
