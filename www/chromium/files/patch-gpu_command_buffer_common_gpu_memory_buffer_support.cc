--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2019-01-30 02:18:02.000000000 +0100
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc	2019-02-01 09:18:35.535261000 +0100
@@ -89,7 +89,7 @@
 uint32_t GetPlatformSpecificTextureTarget() {
 #if defined(OS_MACOSX)
   return GL_TEXTURE_RECTANGLE_ARB;
-#elif defined(OS_ANDROID) || defined(OS_LINUX)
+#elif defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif defined(OS_WIN)
   return GL_TEXTURE_2D;
