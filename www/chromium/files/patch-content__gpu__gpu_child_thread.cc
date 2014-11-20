--- content/gpu/gpu_child_thread.cc.orig	2014-10-10 08:54:14 UTC
+++ content/gpu/gpu_child_thread.cc
@@ -180,6 +180,7 @@
 }
 
 void GpuChildThread::OnCollectGraphicsInfo() {
+#if !defined(OS_FREEBSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -222,6 +223,7 @@
     base::MessageLoop::current()->Quit();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
