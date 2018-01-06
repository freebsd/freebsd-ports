--- src/3rdparty/chromium/content/gpu/in_process_gpu_thread.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/gpu/in_process_gpu_thread.cc
@@ -53,8 +53,6 @@ void InProcessGpuThread::Init() {
   gpu::GPUInfo gpu_info;
   if (!gl::init::InitializeGLOneOff())
     VLOG(1) << "gl::init::InitializeGLOneOff failed";
-  else
-    gpu::CollectContextGraphicsInfo(&gpu_info);
 
   // The process object takes ownership of the thread object, so do not
   // save and delete the pointer.
