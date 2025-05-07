--- ui/gfx/gpu_memory_buffer.h.orig	2025-05-06 12:23:00 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/generic_shared_memory_id.h"
 #include "ui/gfx/geometry/rect.h"
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "ui/gfx/mac/io_surface.h"
@@ -47,7 +47,7 @@ enum GpuMemoryBufferType {
 #if BUILDFLAG(IS_APPLE)
   IO_SURFACE_BUFFER,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NATIVE_PIXMAP,
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -212,7 +212,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBufferHandle {
 
   uint32_t offset = 0;
   uint32_t stride = 0;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif BUILDFLAG(IS_APPLE)
   ScopedIOSurface io_surface;
