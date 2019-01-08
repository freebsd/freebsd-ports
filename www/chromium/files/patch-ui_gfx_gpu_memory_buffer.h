--- ui/gfx/gpu_memory_buffer.h.orig	2018-12-03 21:18:06.000000000 +0100
+++ ui/gfx/gpu_memory_buffer.h	2018-12-15 20:30:42.393665000 +0100
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
 #include "ui/gfx/mac/io_surface.h"
@@ -65,7 +65,7 @@
   base::SharedMemoryHandle handle;
   uint32_t offset;
   int32_t stride;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // TODO(crbug.com/863011): convert this to a scoped handle.
   NativePixmapHandle native_pixmap_handle;
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
