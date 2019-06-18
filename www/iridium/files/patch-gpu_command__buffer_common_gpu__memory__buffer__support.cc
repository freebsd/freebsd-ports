--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2019-03-11 22:00:59 UTC
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -89,7 +89,7 @@ bool IsImageSizeValidForGpuMemoryBufferFormat(const gf
 uint32_t GetPlatformSpecificTextureTarget() {
 #if defined(OS_MACOSX)
   return GL_TEXTURE_RECTANGLE_ARB;
-#elif defined(OS_ANDROID) || defined(OS_LINUX)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif defined(OS_WIN)
   return GL_TEXTURE_2D;
