--- ui/gfx/native_pixmap_handle.cc.orig	2020-07-07 21:57:59 UTC
+++ ui/gfx/native_pixmap_handle.cc
@@ -9,11 +9,15 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <drm_fourcc.h>
 #include "base/posix/eintr_wrapper.h"
 #endif
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 #if defined(OS_FUCHSIA)
 #include <lib/zx/vmo.h>
 #include "base/fuchsia/fuchsia_logging.h"
@@ -21,7 +25,7 @@
 
 namespace gfx {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 static_assert(NativePixmapHandle::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapHandle::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -32,7 +36,7 @@ NativePixmapPlane::NativePixmapPlane() : stride(0), of
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -43,7 +47,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -71,7 +75,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
@@ -97,7 +101,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   clone.modifier = handle.modifier;
 #endif
 
