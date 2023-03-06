--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc
@@ -16,6 +16,10 @@
 #include "base/posix/eintr_wrapper.h"
 #endif
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 #if defined(OS_FUCHSIA)
 #include <lib/zx/vmo.h>
 #include "base/fuchsia/fuchsia_logging.h"
@@ -34,7 +38,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -45,7 +49,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -73,7 +77,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
@@ -99,7 +103,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   clone.modifier = handle.modifier;
 #endif
 
