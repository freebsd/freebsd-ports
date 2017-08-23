--- ui/gfx/native_pixmap_handle.cc.orig	2017-08-02 17:15:59.238862000 +0200
+++ ui/gfx/native_pixmap_handle.cc	2017-08-02 17:16:22.332770000 +0200
@@ -4,7 +4,7 @@
 
 #include "ui/gfx/native_pixmap_handle.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif
 
@@ -29,7 +29,7 @@
 
 NativePixmapHandle::~NativePixmapHandle() {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   std::vector<base::ScopedFD> scoped_fds;
