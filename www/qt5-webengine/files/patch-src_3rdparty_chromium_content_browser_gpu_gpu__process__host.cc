--- src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc
@@ -1076,7 +1076,7 @@ bool GpuProcessHost::LaunchGpuProcess() {
   std::unique_ptr<base::CommandLine> cmd_line =
       std::make_unique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                          : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MACOSX)
