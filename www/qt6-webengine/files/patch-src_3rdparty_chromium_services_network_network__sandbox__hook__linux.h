--- src/3rdparty/chromium/services/network/network_sandbox_hook_linux.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/services/network/network_sandbox_hook_linux.h
@@ -10,7 +10,11 @@
 #include "base/component_export.h"
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
+#if defined(OS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace network {
 
