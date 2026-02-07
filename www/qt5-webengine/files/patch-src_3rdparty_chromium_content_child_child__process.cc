--- src/3rdparty/chromium/content/child/child_process.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/child/child_process.cc
@@ -50,7 +50,7 @@ ChildProcess::ChildProcess(base::ThreadPriority io_thr
   DCHECK(!g_lazy_child_process_tls.Pointer()->Get());
   g_lazy_child_process_tls.Pointer()->Set(this);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   if (IsMojoCoreSharedLibraryEnabled()) {
