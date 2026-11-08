--- gpu/command_buffer/client/internal/mappable_buffer_native_pixmap.cc.orig	2026-08-13 16:48:13 UTC
+++ gpu/command_buffer/client/internal/mappable_buffer_native_pixmap.cc
@@ -64,7 +64,7 @@ MappableBufferNativePixmap::CreateFromHandle(
     viz::SharedImageFormat format,
     gfx::BufferUsage usage) {
   const bool supports_zero_copy_webgpu_import =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       handle.native_pixmap_handle().supports_zero_copy_webgpu_import;
 #else
       false;
