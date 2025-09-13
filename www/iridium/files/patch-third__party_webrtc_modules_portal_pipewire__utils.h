--- third_party/webrtc/modules/portal/pipewire_utils.h.orig	2025-09-11 13:19:19 UTC
+++ third_party/webrtc/modules/portal/pipewire_utils.h
@@ -11,7 +11,9 @@
 #ifndef MODULES_PORTAL_PIPEWIRE_UTILS_H_
 #define MODULES_PORTAL_PIPEWIRE_UTILS_H_
 
+#if defined(__linux__)
 #include <asm-generic/ioctl.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 
