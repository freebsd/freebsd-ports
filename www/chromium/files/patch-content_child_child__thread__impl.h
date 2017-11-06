--- content/child/child_thread_impl.h.orig	2017-06-05 19:03:07 UTC
+++ content/child/child_thread_impl.h
@@ -112,7 +112,7 @@ class CONTENT_EXPORT ChildThreadImpl
   static std::unique_ptr<base::SharedMemory> AllocateSharedMemory(
       size_t buf_size);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetThreadPriority(base::PlatformThreadId id,
                          base::ThreadPriority priority);
 #endif
