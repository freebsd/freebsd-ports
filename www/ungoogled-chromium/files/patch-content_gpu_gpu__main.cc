--- content/gpu/gpu_main.cc.orig	2023-12-23 12:33:28 UTC
+++ content/gpu/gpu_main.cc
@@ -91,7 +91,7 @@
 #include "sandbox/win/src/sandbox.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
@@ -114,7 +114,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -179,7 +179,7 @@ class ContentSandboxHelper : public gpu::GpuSandboxHel
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif BUILDFLAG(IS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -289,7 +289,7 @@ int GpuMain(MainFunctionParams parameters) {
           std::make_unique<base::SingleThreadTaskExecutor>(
               gpu_preferences.message_pump_type);
     }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #error "Unsupported Linux platform."
 #elif BUILDFLAG(IS_MAC)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -328,7 +328,8 @@ int GpuMain(MainFunctionParams parameters) {
   // before it.
   InitializeSkia();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   // Thread type delegate of the process should be registered before
   // first thread type change in ChildProcess constructor.
   // It also needs to be registered before the process has multiple threads,
@@ -436,7 +437,7 @@ int GpuMain(MainFunctionParams parameters) {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
@@ -476,7 +477,7 @@ bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdo
   sandbox_options.accelerated_video_encode_enabled =
       !gpu_prefs.disable_accelerated_video_encode;
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Video decoding of many video streams can use thousands of FDs as well as
   // Exo clients like Lacros.
   // See https://crbug.com/1417237
