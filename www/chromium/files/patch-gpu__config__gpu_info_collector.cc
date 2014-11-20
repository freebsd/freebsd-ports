--- gpu/config/gpu_info_collector.cc.orig	2014-10-10 08:54:15 UTC
+++ gpu/config/gpu_info_collector.cc
@@ -126,7 +126,9 @@
   gpu_info->pixel_shader_version = glsl_version;
   gpu_info->vertex_shader_version = glsl_version;
 
+#ifndef __FreeBSD__
   return CollectDriverInfoGL(gpu_info);
+#endif
 }
 
 void MergeGPUInfoGL(GPUInfo* basic_gpu_info,
