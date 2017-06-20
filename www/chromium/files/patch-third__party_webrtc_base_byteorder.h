--- third_party/webrtc/base/byteorder.h.orig	2017-06-05 19:04:24 UTC
+++ third_party/webrtc/base/byteorder.h
@@ -77,7 +77,7 @@
 #error RTC_ARCH_CPU_BIG_ENDIAN or RTC_ARCH_CPU_LITTLE_ENDIAN must be defined.
 #endif  // defined(RTC_ARCH_CPU_LITTLE_ENDIAN)
 #elif defined(WEBRTC_POSIX)
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 namespace rtc {
