--- content/gpu/gpu_main.cc.orig	2017-12-15 02:04:17.000000000 +0100
+++ content/gpu/gpu_main.cc	2017-12-24 13:25:17.551277000 +0100
@@ -98,7 +98,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*, const gpu::GPUInfo*);
 #elif defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo*);
@@ -156,7 +156,7 @@
 
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -323,7 +323,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info) {
   TRACE_EVENT0("gpu,startup", "Initialize sandbox");
@@ -347,7 +347,7 @@
 
   return res;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo* sandbox_info) {
