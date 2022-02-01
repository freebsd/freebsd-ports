--- content/gpu/gpu_main.cc.orig	2021-12-31 00:57:32 UTC
+++ content/gpu/gpu_main.cc
@@ -89,6 +89,11 @@
 #include "sandbox/policy/sandbox_type.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include "content/public/common/sandbox_init.h"
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
+
 #if defined(OS_MAC)
 #include "base/message_loop/message_pump_mac.h"
 #include "components/metal_util/device_removal.h"
@@ -109,6 +114,8 @@ namespace {
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
+#elif defined(OS_FREEBSD)
+bool StartSandboxFreeBSD();
 #elif defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo*);
 #endif
@@ -169,6 +176,8 @@ class ContentSandboxHelper : public gpu::GpuSandboxHel
                                 const gpu::GpuPreferences& gpu_prefs) override {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
+#elif defined(OS_BSD)
+    return StartSandboxFreeBSD();
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
 #elif defined(OS_MAC)
@@ -263,7 +272,7 @@ int GpuMain(const MainFunctionParams& parameters) {
           std::make_unique<base::SingleThreadTaskExecutor>(
               gpu_preferences.message_pump_type);
     }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #error "Unsupported Linux platform."
 #elif defined(OS_MAC)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -446,6 +455,14 @@ bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdo
   return res;
 }
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+
+#if defined(OS_FREEBSD)
+bool StartSandboxFreeBSD() {
+  return sandbox::policy::SandboxFreeBSD::GetInstance()->InitializeSandbox(
+      sandbox::policy::SandboxTypeFromCommandLine(
+          *base::CommandLine::ForCurrentProcess()));
+}
+#endif  // defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo* sandbox_info) {
