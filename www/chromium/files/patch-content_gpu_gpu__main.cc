--- content/gpu/gpu_main.cc.orig	2017-04-19 19:06:34 UTC
+++ content/gpu/gpu_main.cc
@@ -98,7 +98,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*);
 #elif defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo*);
@@ -152,7 +152,7 @@ class ContentSandboxHelper : public gpu:
 
   bool EnsureSandboxInitialized(
       gpu::GpuWatchdogThread* watchdog_thread) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -313,7 +313,7 @@ int GpuMain(const MainFunctionParams& pa
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread) {
   TRACE_EVENT0("gpu,startup", "Initialize sandbox");
 
