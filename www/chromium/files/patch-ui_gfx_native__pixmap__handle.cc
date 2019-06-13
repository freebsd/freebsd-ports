--- ui/gfx/native_pixmap_handle.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/gfx/native_pixmap_handle.cc
@@ -8,7 +8,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <drm_fourcc.h>
 #include "base/posix/eintr_wrapper.h"
 #endif
@@ -20,7 +20,7 @@
 
 namespace gfx {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 static_assert(NativePixmapPlane::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapPlane::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -32,7 +32,7 @@ NativePixmapPlane::NativePixmapPlane()
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                      base::ScopedFD fd,
 #elif defined(OS_FUCHSIA)
                                      zx::vmo vmo,
@@ -42,7 +42,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
       offset(offset),
       size(size),
       modifier(modifier)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -70,7 +70,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
