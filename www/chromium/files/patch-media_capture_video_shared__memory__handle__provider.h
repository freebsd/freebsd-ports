--- media/capture/video/shared_memory_handle_provider.h.orig	2019-06-04 18:55:25 UTC
+++ media/capture/video/shared_memory_handle_provider.h
@@ -38,10 +38,10 @@ class CAPTURE_EXPORT SharedMemoryHandleProvider
 
 // This requires platforms where base::SharedMemoryHandle is backed by a
 // file descriptor.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool InitAsReadOnlyFromRawFileDescriptor(mojo::ScopedHandle fd_handle,
                                            uint32_t memory_size_in_bytes);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   uint32_t GetMemorySizeInBytes();
 
