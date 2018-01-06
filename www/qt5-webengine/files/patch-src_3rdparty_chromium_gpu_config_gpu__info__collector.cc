--- src/3rdparty/chromium/gpu/config/gpu_info_collector.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_info_collector.cc
@@ -193,8 +193,10 @@ CollectInfoResult CollectGraphicsInfoGL(
   gpu_info->pixel_shader_version = glsl_version;
   gpu_info->vertex_shader_version = glsl_version;
 
+#ifndef __FreeBSD__
   IdentifyActiveGPU(gpu_info);
   return CollectDriverInfoGL(gpu_info);
+#endif
 }
 
 void MergeGPUInfoGL(GPUInfo* basic_gpu_info,
