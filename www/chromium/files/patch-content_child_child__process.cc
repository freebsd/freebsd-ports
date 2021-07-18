--- content/child/child_process.cc.orig	2021-04-14 18:41:02 UTC
+++ content/child/child_process.cc
@@ -52,7 +52,7 @@ ChildProcess::ChildProcess(base::ThreadPriority io_thr
   DCHECK(!g_lazy_child_process_tls.Pointer()->Get());
   g_lazy_child_process_tls.Pointer()->Set(this);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   const bool is_embedded_in_browser_process =
