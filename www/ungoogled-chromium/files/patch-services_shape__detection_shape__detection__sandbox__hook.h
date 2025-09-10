--- services/shape_detection/shape_detection_sandbox_hook.h.orig	2025-09-10 13:22:16 UTC
+++ services/shape_detection/shape_detection_sandbox_hook.h
@@ -5,7 +5,13 @@
 #ifndef SERVICES_SHAPE_DETECTION_SHAPE_DETECTION_SANDBOX_HOOK_H_
 #define SERVICES_SHAPE_DETECTION_SHAPE_DETECTION_SANDBOX_HOOK_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace shape_detection {
 
