--- media/capture/video/shared_memory_handle_provider.h.orig	2019-01-12 22:31:28.927630000 +0100
+++ media/capture/video/shared_memory_handle_provider.h	2019-01-12 22:32:13.374251000 +0100
@@ -38,7 +38,7 @@
 
 // This requires platforms where base::SharedMemoryHandle is backed by a
 // file descriptor.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool InitAsReadOnlyFromRawFileDescriptor(mojo::ScopedHandle fd_handle,
                                            uint32_t memory_size_in_bytes);
 #endif  // defined(OS_LINUX)
