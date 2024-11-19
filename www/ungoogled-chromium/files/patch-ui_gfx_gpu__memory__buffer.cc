--- ui/gfx/gpu_memory_buffer.cc.orig	2024-11-16 12:20:41 UTC
+++ ui/gfx/gpu_memory_buffer.cc
@@ -63,7 +63,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif BUILDFLAG(IS_APPLE)
   handle.io_surface = io_surface;
