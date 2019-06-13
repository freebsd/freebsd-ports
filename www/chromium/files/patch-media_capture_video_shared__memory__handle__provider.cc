--- media/capture/video/shared_memory_handle_provider.cc.orig	2019-06-04 18:55:25 UTC
+++ media/capture/video/shared_memory_handle_provider.cc
@@ -63,7 +63,7 @@ bool SharedMemoryHandleProvider::InitFromMojoHandle(
   return true;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool SharedMemoryHandleProvider::InitAsReadOnlyFromRawFileDescriptor(
     mojo::ScopedHandle fd_handle,
     uint32_t memory_size_in_bytes) {
@@ -80,7 +80,7 @@ bool SharedMemoryHandleProvider::InitAsReadOnlyFromRaw
   shared_memory_.emplace(memory_handle, read_only_flag_);
   return true;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 mojo::ScopedSharedBufferHandle
 SharedMemoryHandleProvider::GetHandleForInterProcessTransit(bool read_only) {
