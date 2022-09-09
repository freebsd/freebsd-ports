--- content/child/child_process.cc.orig	2022-08-31 12:19:35 UTC
+++ content/child/child_process.cc
@@ -67,7 +67,7 @@ ChildProcess::ChildProcess(base::ThreadType io_thread_
   DCHECK(!g_lazy_child_process_tls.Pointer()->Get());
   g_lazy_child_process_tls.Pointer()->Set(this);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   const bool is_embedded_in_browser_process =
