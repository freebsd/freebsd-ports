--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc
@@ -108,7 +108,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.id = id;
   handle.offset = offset;
   handle.stride = stride;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif BUILDFLAG(IS_APPLE)
   handle.io_surface = io_surface;
