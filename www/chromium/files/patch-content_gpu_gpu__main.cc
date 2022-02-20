--- content/gpu/gpu_main.cc.orig	2022-02-07 13:39:41 UTC
+++ content/gpu/gpu_main.cc
@@ -83,7 +83,7 @@
 #include "sandbox/win/src/sandbox.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "content/public/common/sandbox_init.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
@@ -106,7 +106,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -168,7 +168,7 @@ class ContentSandboxHelper : public gpu::GpuSandboxHel
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -264,7 +264,7 @@ int GpuMain(MainFunctionParams parameters) {
           std::make_unique<base::SingleThreadTaskExecutor>(
               gpu_preferences.message_pump_type);
     }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #error "Unsupported Linux platform."
 #elif defined(OS_MAC)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -407,17 +407,19 @@ int GpuMain(MainFunctionParams parameters) {
 
 namespace {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
   TRACE_EVENT0("gpu,startup", "Initialize sandbox");
 
+#if !defined(OS_BSD)
   if (watchdog_thread) {
     // SandboxLinux needs to be able to ensure that the thread
     // has really been stopped.
     sandbox::policy::SandboxLinux::GetInstance()->StopThread(watchdog_thread);
   }
+#endif
 
   // SandboxLinux::InitializeSandbox() must always be called
   // with only one thread.
@@ -438,11 +440,13 @@ bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdo
           *base::CommandLine::ForCurrentProcess()),
       base::BindOnce(GpuProcessPreSandboxHook), sandbox_options);
 
+#if !defined(OS_BSD)
   if (watchdog_thread) {
     base::Thread::Options thread_options;
     thread_options.timer_slack = base::TIMER_SLACK_MAXIMUM;
     watchdog_thread->StartWithOptions(std::move(thread_options));
   }
+#endif
 
   return res;
 }
