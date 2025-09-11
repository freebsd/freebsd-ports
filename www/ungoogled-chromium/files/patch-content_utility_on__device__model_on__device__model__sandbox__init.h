--- content/utility/on_device_model/on_device_model_sandbox_init.h.orig	2025-09-10 13:22:16 UTC
+++ content/utility/on_device_model/on_device_model_sandbox_init.h
@@ -11,6 +11,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 // Must be called in the service's process before sandbox initialization.
@@ -21,7 +25,7 @@ namespace on_device_model {
 // Must be called in the service's process after the run loop finished.
 [[nodiscard]] bool Shutdown();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void AddSandboxLinuxOptions(sandbox::policy::SandboxLinux::Options& options);
 
 [[nodiscard]] bool PreSandboxHook(
