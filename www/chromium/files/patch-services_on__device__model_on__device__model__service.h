--- services/on_device_model/on_device_model_service.h.orig	2024-11-14 07:57:23 UTC
+++ services/on_device_model/on_device_model_service.h
@@ -31,6 +31,10 @@ class OnDeviceModelInternalImpl;
 class TsHolder;
 }
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelService
@@ -44,7 +48,7 @@ class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelS
   // Must be called in the service's process after the run loop finished.
   [[nodiscard]] static bool Shutdown();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static void AddSandboxLinuxOptions(
       sandbox::policy::SandboxLinux::Options& options);
 #endif
