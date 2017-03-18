--- content/child/child_thread_impl.cc.orig	2017-03-09 20:04:32 UTC
+++ content/child/child_thread_impl.cc
@@ -706,7 +706,7 @@ std::unique_ptr<base::SharedMemory> Chil
   return base::MakeUnique<base::SharedMemory>(shared_buf, false);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void ChildThreadImpl::SetThreadPriority(base::PlatformThreadId id,
                                         base::ThreadPriority priority) {
   Send(new ChildProcessHostMsg_SetThreadPriority(id, priority));
