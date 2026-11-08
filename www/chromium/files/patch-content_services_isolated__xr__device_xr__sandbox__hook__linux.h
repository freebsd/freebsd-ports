--- content/services/isolated_xr_device/xr_sandbox_hook_linux.h.orig	2026-10-18 13:29:39 UTC
+++ content/services/isolated_xr_device/xr_sandbox_hook_linux.h
@@ -9,7 +9,11 @@
 #include <string>
 #include <string_view>
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace vr {
 
