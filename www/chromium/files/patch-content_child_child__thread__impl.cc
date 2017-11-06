--- content/child/child_thread_impl.cc.orig	2017-06-05 19:03:07 UTC
+++ content/child/child_thread_impl.cc
@@ -698,7 +698,7 @@ std::unique_ptr<base::SharedMemory> ChildThreadImpl::A
   return base::MakeUnique<base::SharedMemory>(shared_buf, false);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void ChildThreadImpl::SetThreadPriority(base::PlatformThreadId id,
                                         base::ThreadPriority priority) {
   Send(new ChildProcessHostMsg_SetThreadPriority(id, priority));
