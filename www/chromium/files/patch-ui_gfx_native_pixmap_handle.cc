--- ui/gfx/native_pixmap_handle.cc.orig	2018-03-20 23:05:56.000000000 +0100
+++ ui/gfx/native_pixmap_handle.cc	2018-03-24 19:09:06.975980000 +0100
@@ -4,14 +4,14 @@
 
 #include "ui/gfx/native_pixmap_handle.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <drm_fourcc.h>
 #include "base/posix/eintr_wrapper.h"
 #endif
 
 namespace gfx {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 static_assert(NativePixmapPlane::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapPlane::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -36,7 +36,7 @@
 
 NativePixmapHandle::~NativePixmapHandle() {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   std::vector<base::ScopedFD> scoped_fds;
