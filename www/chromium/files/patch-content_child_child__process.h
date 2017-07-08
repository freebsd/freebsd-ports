--- content/child/child_process.h.orig	2017-06-05 19:03:07 UTC
+++ content/child/child_process.h
@@ -79,7 +79,7 @@ class CONTENT_EXPORT ChildProcess {
   void AddRefProcess();
   void ReleaseProcess();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetIOThreadPriority(base::ThreadPriority io_thread_priority);
 #endif
 
