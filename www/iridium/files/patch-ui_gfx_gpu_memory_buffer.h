--- ui/gfx/gpu_memory_buffer.h.orig	2017-08-02 16:52:58.362137000 +0200
+++ ui/gfx/gpu_memory_buffer.h	2017-08-02 16:53:34.724326000 +0200
@@ -16,7 +16,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
 #include "ui/gfx/mac/io_surface.h"
@@ -48,7 +48,7 @@
   base::SharedMemoryHandle handle;
   uint32_t offset;
   int32_t stride;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   ScopedRefCountedIOSurfaceMachPort mach_port;
