--- src/3rdparty/chromium/content/child/child_process.cc.orig	2023-11-03 10:09:45 UTC
+++ src/3rdparty/chromium/content/child/child_process.cc
@@ -66,7 +66,7 @@ ChildProcess::ChildProcess(base::ThreadType io_thread_
                                thread_pool_init_params)
     : resetter_(&child_process, this, nullptr),
       io_thread_(std::make_unique<ChildIOThread>()) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   const bool is_embedded_in_browser_process =
