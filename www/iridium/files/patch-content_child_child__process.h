--- content/child/child_process.h.orig	2017-04-19 19:06:33 UTC
+++ content/child/child_process.h
@@ -82,7 +82,7 @@ class CONTENT_EXPORT ChildProcess {
   void AddRefProcess();
   void ReleaseProcess();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetIOThreadPriority(base::ThreadPriority io_thread_priority);
 #endif
 
