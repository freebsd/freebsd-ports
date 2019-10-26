--- src/3rdparty/chromium/third_party/webrtc/rtc_base/byte_order.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/byte_order.h
@@ -79,7 +79,7 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 #elif defined(WEBRTC_POSIX)
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 namespace rtc {
