--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2022-02-07 13:39:41 UTC
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -134,7 +134,7 @@ uint32_t GetPlatformSpecificTextureTarget() {
 #if defined(OS_MAC)
   return macos_specific_texture_target;
 #elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif defined(OS_FUCHSIA)
   return GL_TEXTURE_2D;
@@ -166,7 +166,7 @@ GPU_EXPORT bool NativeBufferNeedsPlatformSpecificTextu
     gfx::BufferFormat format,
     gfx::BufferPlane plane) {
 #if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||
