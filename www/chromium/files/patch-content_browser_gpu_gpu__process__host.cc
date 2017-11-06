--- content/browser/gpu/gpu_process_host.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -965,7 +965,7 @@ bool GpuProcessHost::LaunchGpuProcess(gpu::GpuPreferen
   std::unique_ptr<base::CommandLine> cmd_line =
       base::MakeUnique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                            ChildProcessHost::CHILD_NORMAL;
 #else
