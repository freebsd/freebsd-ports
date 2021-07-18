--- ui/gfx/gpu_memory_buffer.h.orig	2021-04-14 18:41:39 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/gfx_export.h"
 #include "ui/gfx/hdr_metadata.h"
 
-#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif defined(OS_MAC)
 #include "ui/gfx/mac/io_surface.h"
@@ -70,7 +70,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle {
   base::UnsafeSharedMemoryRegion region;
   uint32_t offset = 0;
   int32_t stride = 0;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif defined(OS_MAC)
   ScopedIOSurface io_surface;
