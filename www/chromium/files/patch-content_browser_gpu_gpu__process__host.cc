--- content/browser/gpu/gpu_process_host.cc.orig	2019-06-04 18:55:23 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -1082,7 +1082,7 @@ bool GpuProcessHost::LaunchGpuProcess() {
   std::unique_ptr<base::CommandLine> cmd_line =
       std::make_unique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                          : ChildProcessHost::CHILD_NORMAL;
 #else
