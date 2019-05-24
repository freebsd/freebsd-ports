--- ui/gfx/native_pixmap_handle.cc.orig	2019-04-30 22:23:42 UTC
+++ ui/gfx/native_pixmap_handle.cc
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
@@ -36,7 +36,7 @@ NativePixmapHandle::NativePixmapHandle(const NativePix
 
 NativePixmapHandle::~NativePixmapHandle() {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   std::vector<base::ScopedFD> scoped_fds;
@@ -53,6 +53,6 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
   clone.planes = handle.planes;
   return clone;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace gfx
