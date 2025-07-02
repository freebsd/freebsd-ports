--- ui/gfx/gpu_memory_buffer.cc.orig	2025-07-02 06:08:04 UTC
+++ ui/gfx/gpu_memory_buffer.cc
@@ -100,7 +100,7 @@ GpuMemoryBufferHandle::GpuMemoryBufferHandle(DXGIHandl
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 GpuMemoryBufferHandle::GpuMemoryBufferHandle(
     NativePixmapHandle native_pixmap_handle)
     : type(GpuMemoryBufferType::NATIVE_PIXMAP),
@@ -138,7 +138,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.id = id;
   handle.offset = offset;
   handle.stride = stride;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle_ = CloneHandleForIPC(native_pixmap_handle_);
 #elif BUILDFLAG(IS_APPLE)
   handle.io_surface = io_surface;
