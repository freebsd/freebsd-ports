--- media/capture/video/shared_memory_handle_provider.h.orig	2019-03-11 22:00:59 UTC
+++ media/capture/video/shared_memory_handle_provider.h
@@ -38,7 +38,7 @@ class CAPTURE_EXPORT SharedMemoryHandleProvider
 
 // This requires platforms where base::SharedMemoryHandle is backed by a
 // file descriptor.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool InitAsReadOnlyFromRawFileDescriptor(mojo::ScopedHandle fd_handle,
                                            uint32_t memory_size_in_bytes);
 #endif  // defined(OS_LINUX)
