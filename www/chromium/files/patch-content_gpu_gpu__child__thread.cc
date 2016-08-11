--- content/gpu/gpu_child_thread.cc.orig	2016-05-11 19:02:21 UTC
+++ content/gpu/gpu_child_thread.cc
@@ -382,6 +382,7 @@ void GpuChildThread::StopWatchdog() {
 }
 
 void GpuChildThread::OnCollectGraphicsInfo() {
+#if !defined(OS_FREEBSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -424,6 +425,7 @@ void GpuChildThread::OnCollectGraphicsIn
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
