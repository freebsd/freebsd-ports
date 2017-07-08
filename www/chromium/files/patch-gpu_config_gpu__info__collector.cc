--- gpu/config/gpu_info_collector.cc.orig	2017-06-05 19:03:08 UTC
+++ gpu/config/gpu_info_collector.cc
@@ -194,8 +194,10 @@ CollectInfoResult CollectGraphicsInfoGL(GPUInfo* gpu_i
   gpu_info->pixel_shader_version = glsl_version;
   gpu_info->vertex_shader_version = glsl_version;
 
+#if !defined(OS_BSD)
   IdentifyActiveGPU(gpu_info);
   return CollectDriverInfoGL(gpu_info);
+#endif
 }
 
 void MergeGPUInfoGL(GPUInfo* basic_gpu_info,
