--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2021-07-19 18:45:17 UTC
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -119,7 +119,7 @@ gfx::BufferFormat GetPlaneBufferFormat(gfx::BufferPlan
 uint32_t GetPlatformSpecificTextureTarget() {
 #if defined(OS_MAC)
   return macos_specific_texture_target;
-#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_WIN)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif defined(OS_FUCHSIA)
@@ -150,7 +150,7 @@ GPU_EXPORT uint32_t GetBufferTextureTarget(gfx::Buffer
 
 GPU_EXPORT bool NativeBufferNeedsPlatformSpecificTextureTarget(
     gfx::BufferFormat format) {
-#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_WIN)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
