--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc
@@ -33,7 +33,7 @@ NativePixmapPlane::NativePixmapPlane() : stride(0), of
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -44,7 +44,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -72,7 +72,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
