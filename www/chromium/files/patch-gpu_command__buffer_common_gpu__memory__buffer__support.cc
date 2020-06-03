--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2020-05-13 18:40:32 UTC
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -54,7 +54,7 @@ bool IsImageSizeValidForGpuMemoryBufferFormat(const gf
 uint32_t GetPlatformSpecificTextureTarget() {
 #if defined(OS_MACOSX)
   return macos_specific_texture_target;
-#elif defined(OS_ANDROID) || defined(OS_LINUX)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif defined(OS_WIN) || defined(OS_FUCHSIA)
   return GL_TEXTURE_2D;
@@ -84,7 +84,7 @@ GPU_EXPORT uint32_t GetBufferTextureTarget(gfx::Buffer
 
 GPU_EXPORT bool NativeBufferNeedsPlatformSpecificTextureTarget(
     gfx::BufferFormat format) {
-#if defined(USE_OZONE) || defined(OS_LINUX)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||
