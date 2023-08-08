--- content/child/child_process.cc.orig	2023-07-21 09:49:17 UTC
+++ content/child/child_process.cc
@@ -67,7 +67,7 @@ ChildProcess::ChildProcess(base::ThreadType io_thread_
       io_thread_(std::make_unique<ChildIOThread>()) {
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const bool is_embedded_in_browser_process =
       !command_line.HasSwitch(switches::kProcessType);
   if (IsMojoCoreSharedLibraryEnabled() && !is_embedded_in_browser_process) {
