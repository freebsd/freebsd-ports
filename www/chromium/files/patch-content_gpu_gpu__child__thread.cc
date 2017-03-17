--- content/gpu/gpu_child_thread.cc.orig	2017-03-09 20:04:32 UTC
+++ content/gpu/gpu_child_thread.cc
@@ -387,6 +387,7 @@ void GpuChildThread::OnCollectGraphicsIn
   if (dead_on_arrival_)
     return;
 
+#if !defined(OS_BSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -438,6 +439,7 @@ void GpuChildThread::OnCollectGraphicsIn
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
