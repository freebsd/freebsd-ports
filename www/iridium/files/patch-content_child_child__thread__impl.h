--- content/child/child_thread_impl.h.orig	2017-04-19 19:06:33 UTC
+++ content/child/child_thread_impl.h
@@ -116,7 +116,7 @@ class CONTENT_EXPORT ChildThreadImpl
   static std::unique_ptr<base::SharedMemory> AllocateSharedMemory(
       size_t buf_size);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(base::PlatformThreadId id,
                          base::ThreadPriority priority);
 #endif
