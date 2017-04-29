--- content/gpu/in_process_gpu_thread.cc.orig	2017-04-19 19:06:34 UTC
+++ content/gpu/in_process_gpu_thread.cc
@@ -54,8 +54,6 @@ void InProcessGpuThread::Init() {
   gpu::GPUInfo gpu_info;
   if (!gl::init::InitializeGLOneOff())
     VLOG(1) << "gl::init::InitializeGLOneOff failed";
-  else
-    gpu::CollectContextGraphicsInfo(&gpu_info);
 
   gpu::GpuFeatureInfo gpu_feature_info =
       gpu::GetGpuFeatureInfo(gpu_info, *base::CommandLine::ForCurrentProcess());
