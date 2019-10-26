--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc.orig	2019-03-01 17:04:22 UTC
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc
@@ -38,7 +38,7 @@ NativePixmapHandle::NativePixmapHandle(const NativePix
 
 NativePixmapHandle::~NativePixmapHandle() {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   std::vector<base::ScopedFD> scoped_fds;
