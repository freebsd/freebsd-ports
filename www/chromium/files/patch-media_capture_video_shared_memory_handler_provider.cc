--- media/capture/video/shared_memory_handle_provider.cc.orig	2019-01-12 22:31:08.999805000 +0100
+++ media/capture/video/shared_memory_handle_provider.cc	2019-01-12 22:31:53.741578000 +0100
@@ -63,7 +63,7 @@
   return true;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool SharedMemoryHandleProvider::InitAsReadOnlyFromRawFileDescriptor(
     mojo::ScopedHandle fd_handle,
     uint32_t memory_size_in_bytes) {
