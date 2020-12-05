--- content/child/child_process.cc.orig	2020-11-16 14:35:28 UTC
+++ content/child/child_process.cc
@@ -50,7 +50,7 @@ ChildProcess::ChildProcess(base::ThreadPriority io_thr
   DCHECK(!g_lazy_child_process_tls.Pointer()->Get());
   g_lazy_child_process_tls.Pointer()->Set(this);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   if (IsMojoCoreSharedLibraryEnabled()) {
