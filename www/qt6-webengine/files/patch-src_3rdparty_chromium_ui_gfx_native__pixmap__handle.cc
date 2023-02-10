--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !defined(TOOLKIT_QT)
 #include <drm_fourcc.h>
 #endif
@@ -23,6 +23,10 @@
 #include "base/fuchsia/fuchsia_logging.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !defined(TOOLKIT_QT)
@@ -36,7 +40,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -47,7 +51,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       ,
       fd(std::move(fd))
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -75,7 +79,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     DCHECK(plane.fd.is_valid());
     // Combining the HANDLE_EINTR and ScopedFD's constructor causes the compiler
     // to emit some very strange assembly that tends to cause FD ownership
@@ -105,7 +109,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   clone.modifier = handle.modifier;
   clone.supports_zero_copy_webgpu_import =
       handle.supports_zero_copy_webgpu_import;
