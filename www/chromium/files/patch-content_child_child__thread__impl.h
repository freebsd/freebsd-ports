--- content/child/child_thread_impl.h.orig	2017-02-02 02:02:53 UTC
+++ content/child/child_thread_impl.h
@@ -130,7 +130,7 @@ class CONTENT_EXPORT ChildThreadImpl
       IPC::Sender* sender,
       bool* out_of_memory);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(base::PlatformThreadId id,
                          base::ThreadPriority priority);
 #endif
