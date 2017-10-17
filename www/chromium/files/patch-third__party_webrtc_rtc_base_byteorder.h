--- third_party/webrtc/rtc_base/byteorder.h.orig	2017-09-07 00:29:50.482044000 +0200
+++ third_party/webrtc/rtc_base/byteorder.h	2017-09-07 00:30:15.190287000 +0200
@@ -77,7 +77,7 @@
 #error RTC_ARCH_CPU_BIG_ENDIAN or RTC_ARCH_CPU_LITTLE_ENDIAN must be defined.
 #endif  // defined(RTC_ARCH_CPU_LITTLE_ENDIAN)
 #elif defined(WEBRTC_POSIX)
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 namespace rtc {
