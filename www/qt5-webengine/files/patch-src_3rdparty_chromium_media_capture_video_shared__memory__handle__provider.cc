--- src/3rdparty/chromium/media/capture/video/shared_memory_handle_provider.cc.orig	2019-03-07 09:23:57 UTC
+++ src/3rdparty/chromium/media/capture/video/shared_memory_handle_provider.cc
@@ -63,7 +63,7 @@ bool SharedMemoryHandleProvider::InitFromMojoHandle(
   return true;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool SharedMemoryHandleProvider::InitAsReadOnlyFromRawFileDescriptor(
     mojo::ScopedHandle fd_handle,
     uint32_t memory_size_in_bytes) {
