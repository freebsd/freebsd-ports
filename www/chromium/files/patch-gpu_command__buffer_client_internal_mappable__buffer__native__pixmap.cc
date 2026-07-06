--- gpu/command_buffer/client/internal/mappable_buffer_native_pixmap.cc.orig	2026-07-01 06:24:19 UTC
+++ gpu/command_buffer/client/internal/mappable_buffer_native_pixmap.cc
@@ -62,7 +62,7 @@ MappableBufferNativePixmap::CreateFromHandle(
     viz::SharedImageFormat format,
     gfx::BufferUsage usage) {
   const bool supports_zero_copy_webgpu_import =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       handle.native_pixmap_handle().supports_zero_copy_webgpu_import;
 #else
       false;
