--- content/browser/gpu/gpu_process_host.cc.orig	2021-01-18 21:28:57 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -228,7 +228,7 @@ static const char* const kSwitchNames[] = {
     sandbox::policy::switches::kGpuSandboxFailuresFatal,
     sandbox::policy::switches::kDisableGpuSandbox,
     sandbox::policy::switches::kNoSandbox,
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)) || defined(OS_BSD)
     switches::kDisableDevShmUsage,
 #endif
 #if defined(OS_WIN)
@@ -1135,7 +1135,7 @@ bool GpuProcessHost::LaunchGpuProcess() {
   std::unique_ptr<base::CommandLine> cmd_line =
       std::make_unique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                          : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
