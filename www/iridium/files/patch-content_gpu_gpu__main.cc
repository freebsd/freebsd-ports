--- content/gpu/gpu_main.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/gpu/gpu_main.cc	2018-03-04 01:23:12.209864000 +0100
@@ -76,7 +76,7 @@
 #include "ui/gfx/x/x11_switches.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/common/font_config_ipc_linux.h"
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "content/public/common/common_sandbox_support_linux.h"
@@ -102,7 +102,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -163,7 +163,7 @@
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -340,7 +340,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
@@ -378,7 +378,7 @@
 
   return res;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo* sandbox_info) {
