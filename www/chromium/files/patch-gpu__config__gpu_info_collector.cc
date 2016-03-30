--- gpu/config/gpu_info_collector.cc.orig	2016-03-04 22:55:40.742558914 +0100
+++ gpu/config/gpu_info_collector.cc	2016-03-04 22:55:58.941556712 +0100
@@ -167,8 +167,10 @@
   gpu_info->pixel_shader_version = glsl_version;
   gpu_info->vertex_shader_version = glsl_version;
 
+#ifndef __FreeBSD__
   IdentifyActiveGPU(gpu_info);
   return CollectDriverInfoGL(gpu_info);
+#endif
 }
 
 void MergeGPUInfoGL(GPUInfo* basic_gpu_info,
