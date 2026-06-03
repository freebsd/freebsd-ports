--- components/on_device_translation/service/sandbox_hook.h.orig	2026-02-15 10:01:45 UTC
+++ components/on_device_translation/service/sandbox_hook.h
@@ -5,7 +5,13 @@
 #ifndef COMPONENTS_ON_DEVICE_TRANSLATION_SERVICE_SANDBOX_HOOK_H_
 #define COMPONENTS_ON_DEVICE_TRANSLATION_SERVICE_SANDBOX_HOOK_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace on_device_translation {
 
