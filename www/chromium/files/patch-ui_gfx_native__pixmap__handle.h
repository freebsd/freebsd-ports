--- ui/gfx/native_pixmap_handle.h.orig	2019-06-04 18:55:50 UTC
+++ ui/gfx/native_pixmap_handle.h
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -35,7 +35,7 @@ struct GFX_EXPORT NativePixmapPlane {
   NativePixmapPlane(int stride,
                     int offset,
                     uint64_t size,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                     base::ScopedFD fd,
 #elif defined(OS_FUCHSIA)
                     zx::vmo vmo,
@@ -58,7 +58,7 @@ struct GFX_EXPORT NativePixmapPlane {
   // Chromium code. Also one per plane per entry.
   uint64_t modifier;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // File descriptor for the underlying memory object (usually dmabuf).
   base::ScopedFD fd;
 #elif defined(OS_FUCHSIA)
