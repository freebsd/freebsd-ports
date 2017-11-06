--- src/3rdparty/chromium/content/gpu/gpu_child_thread.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/content/gpu/gpu_child_thread.cc
@@ -306,6 +306,7 @@ void GpuChildThread::StopWatchdog() {
 }
 
 void GpuChildThread::OnCollectGraphicsInfo() {
+#if !defined(OS_FREEBSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -348,6 +349,7 @@ void GpuChildThread::OnCollectGraphicsInfo() {
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif 
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
