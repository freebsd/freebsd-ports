--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
 #include "ui/gfx/mac/io_surface.h"
@@ -57,7 +57,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle {
   base::SharedMemoryHandle handle;
   uint32_t offset;
   int32_t stride;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   ScopedRefCountedIOSurfaceMachPort mach_port;
