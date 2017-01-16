--- content/gpu/in_process_gpu_thread.cc.orig	2016-12-18 18:45:05.278739000 +0000
+++ content/gpu/in_process_gpu_thread.cc	2016-12-18 18:45:21.876600000 +0000
@@ -53,8 +53,6 @@
   gpu::GPUInfo gpu_info;
   if (!gl::init::InitializeGLOneOff())
     VLOG(1) << "gl::init::InitializeGLOneOff failed";
-  else
-    gpu::CollectContextGraphicsInfo(&gpu_info);
 
   // The process object takes ownership of the thread object, so do not
   // save and delete the pointer.
