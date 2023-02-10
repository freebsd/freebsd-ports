--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.cc
@@ -54,7 +54,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif BUILDFLAG(IS_MAC)
   handle.io_surface = io_surface;
