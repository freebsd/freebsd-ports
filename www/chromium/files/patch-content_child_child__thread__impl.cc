--- content/child/child_thread_impl.cc.orig	2017-02-02 02:02:53 UTC
+++ content/child/child_thread_impl.cc
@@ -751,7 +751,7 @@ std::unique_ptr<base::SharedMemory> Chil
   return base::MakeUnique<base::SharedMemory>(shared_buf, false);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void ChildThreadImpl::SetThreadPriority(base::PlatformThreadId id,
                                         base::ThreadPriority priority) {
   Send(new ChildProcessHostMsg_SetThreadPriority(id, priority));
