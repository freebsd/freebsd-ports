--- third_party/webrtc/rtc_base/cpu_info.cc.orig	2025-08-07 06:57:29 UTC
+++ third_party/webrtc/rtc_base/cpu_info.cc
@@ -22,7 +22,9 @@
 #elif defined(WEBRTC_FUCHSIA)
 #include <zircon/syscalls.h>
 #elif defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <features.h>
+#endif
 #include <stdlib.h>
 #include <string.h>  // IWYU pragma: keep
 #include <unistd.h>
