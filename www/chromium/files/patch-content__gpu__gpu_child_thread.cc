--- content/gpu/gpu_child_thread.cc.orig	2014-10-02 17:39:47 UTC
+++ content/gpu/gpu_child_thread.cc
@@ -179,6 +179,7 @@
 }
 
 void GpuChildThread::OnCollectGraphicsInfo() {
+#if !defined(OS_FREEBSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -218,6 +219,7 @@
     base::MessageLoop::current()->Quit();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
