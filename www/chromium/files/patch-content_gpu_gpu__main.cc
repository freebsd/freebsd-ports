--- content/gpu/gpu_main.cc.orig	2016-12-01 23:02:13.000000000 +0000
+++ content/gpu/gpu_main.cc	2016-12-13 17:52:18.210016000 +0000
@@ -92,7 +92,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*);
 #elif defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo*);
@@ -145,7 +145,7 @@
 
   bool EnsureSandboxInitialized(
       gpu::GpuWatchdogThread* watchdog_thread) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -292,7 +292,7 @@
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread) {
   TRACE_EVENT0("gpu,startup", "Initialize sandbox");
 
