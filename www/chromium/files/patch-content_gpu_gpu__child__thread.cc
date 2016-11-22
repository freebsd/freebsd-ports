--- content/gpu/gpu_child_thread.cc.orig	2016-10-06 04:02:19.000000000 +0300
+++ content/gpu/gpu_child_thread.cc	2016-10-14 15:27:34.081648000 +0300
@@ -419,6 +419,7 @@
   if (dead_on_arrival_)
     return;
 
+#if !defined(OS_BSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -461,6 +462,7 @@
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnGetVideoMemoryUsageStats() {
