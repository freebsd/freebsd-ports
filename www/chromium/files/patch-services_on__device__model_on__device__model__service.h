--- services/on_device_model/on_device_model_service.h.orig	2024-01-30 07:53:34 UTC
+++ services/on_device_model/on_device_model_service.h
@@ -18,6 +18,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelService
@@ -27,7 +31,7 @@ class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelS
   // These are defined separately in pre_sandbox_init.cc for explicit security
   // review coverage.
   [[nodiscard]] static bool PreSandboxInit();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static void AddSandboxLinuxOptions(
       sandbox::policy::SandboxLinux::Options& options);
 #endif
