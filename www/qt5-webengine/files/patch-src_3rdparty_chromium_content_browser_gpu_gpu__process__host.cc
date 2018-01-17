--- src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc
@@ -984,7 +984,7 @@ bool GpuProcessHost::LaunchGpuProcess(gp
   base::CommandLine* cmd_line =
       new base::CommandLine(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                            ChildProcessHost::CHILD_NORMAL;
 #else
