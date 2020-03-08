--- ui/gfx/gpu_memory_buffer.h.orig	2020-03-03 18:54:06 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(USE_OZONE) || defined(OS_LINUX)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
 #include "ui/gfx/mac/io_surface.h"
@@ -65,7 +65,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle {
   base::UnsafeSharedMemoryRegion region;
   uint32_t offset;
   int32_t stride;
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   ScopedRefCountedIOSurfaceMachPort mach_port;
