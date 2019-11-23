--- src/3rdparty/chromium/services/service_manager/sandbox/linux/bpf_renderer_policy_linux.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/services/service_manager/sandbox/linux/bpf_renderer_policy_linux.cc
@@ -15,6 +15,11 @@
 #include "sandbox/linux/system_headers/linux_syscalls.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 
+// On PPC64, TCGETS is defined in terms of struct termios, so we must include termios.h
+#ifdef __powerpc64__
+#include <termios.h>
+#endif
+
 // TODO(vignatti): replace the local definitions below with #include
 // <linux/dma-buf.h> once kernel version 4.6 becomes widely used.
 #include <linux/types.h>
