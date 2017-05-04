--- content/gpu/gpu_child_thread.cc.orig	2017-04-19 19:06:34 UTC
+++ content/gpu/gpu_child_thread.cc
@@ -398,6 +398,7 @@ void GpuChildThread::OnCollectGraphicsIn
   }
 #endif
 
+#if !defined(OS_BSD)
 #if defined(OS_WIN)
   // GPU full info collection should only happen on un-sandboxed GPU process
   // or single process/in-process gpu mode on Windows.
@@ -420,6 +421,7 @@ void GpuChildThread::OnCollectGraphicsIn
     base::MessageLoop::current()->QuitWhenIdle();
   }
 #endif  // OS_WIN
+#endif  // XXX(rene) !FreeBSD
 }
 
 void GpuChildThread::OnClean() {
