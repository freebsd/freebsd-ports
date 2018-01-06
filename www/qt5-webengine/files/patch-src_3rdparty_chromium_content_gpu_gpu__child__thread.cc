--- src/3rdparty/chromium/content/gpu/gpu_child_thread.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/gpu/gpu_child_thread.cc
@@ -383,6 +383,7 @@ void GpuChildThread::OnCollectGraphicsIn
   if (dead_on_arrival_)
     return;
 
+#if !defined(OS_BSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -434,6 +435,7 @@ void GpuChildThread::OnCollectGraphicsIn
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
