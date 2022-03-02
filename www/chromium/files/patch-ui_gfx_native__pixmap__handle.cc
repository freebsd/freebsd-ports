--- ui/gfx/native_pixmap_handle.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/gfx/native_pixmap_handle.cc
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <drm_fourcc.h>
 #include <unistd.h>
 
@@ -21,9 +21,13 @@
 #include "base/fuchsia/fuchsia_logging.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 static_assert(NativePixmapHandle::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapHandle::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -34,7 +38,7 @@ NativePixmapPlane::NativePixmapPlane() : stride(0), of
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -45,7 +49,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       ,
       fd(std::move(fd))
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -73,7 +77,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
@@ -99,7 +103,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   clone.modifier = handle.modifier;
 #endif
 
