--- gpu/command_buffer/service/shared_context_state.h.orig	2023-11-22 14:00:11 UTC
+++ gpu/command_buffer/service/shared_context_state.h
@@ -392,6 +392,8 @@ class GPU_GLES2_EXPORT SharedContextState
   std::vector<uint8_t> scratch_deserialization_buffer_;
   raw_ptr<gpu::raster::GrShaderCache, DanglingUntriaged> gr_shader_cache_ =
       nullptr;
+  raw_ptr<GpuProcessShmCount, DanglingUntriaged> use_shader_cache_shm_count_ =
+      nullptr;
 
   // |need_context_state_reset| is set whenever Skia may have altered the
   // driver's GL state.
