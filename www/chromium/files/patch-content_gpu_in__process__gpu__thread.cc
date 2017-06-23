--- content/gpu/in_process_gpu_thread.cc.orig	2017-06-05 19:03:07 UTC
+++ content/gpu/in_process_gpu_thread.cc
@@ -55,8 +55,6 @@ void InProcessGpuThread::Init() {
   gpu::GPUInfo gpu_info;
   if (!gl::init::InitializeGLOneOff())
     VLOG(1) << "gl::init::InitializeGLOneOff failed";
-  else
-    gpu::CollectContextGraphicsInfo(&gpu_info);
 
   gpu::GpuFeatureInfo gpu_feature_info =
       gpu::GetGpuFeatureInfo(gpu_info, *base::CommandLine::ForCurrentProcess());
