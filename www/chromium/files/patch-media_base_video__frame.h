--- media/base/video_frame.h.orig	2017-02-02 02:02:55 UTC
+++ media/base/video_frame.h
@@ -62,7 +62,7 @@ class MEDIA_EXPORT VideoFrame : public b
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Pixels are backed by Shared Memory.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE or another
     // meaningful name and handle it appropriately in all cases.
     STORAGE_DMABUFS = 5,  // Each plane is stored into a DmaBuf.
@@ -186,7 +186,7 @@ class MEDIA_EXPORT VideoFrame : public b
       uint8_t* a_data,
       base::TimeDelta timestamp);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/Documentation/dma-buf-sharing.txt) with a
   // VideoFrame. The dmabuf fds are dup()ed on creation, so that the VideoFrame
@@ -336,7 +336,7 @@ class MEDIA_EXPORT VideoFrame : public b
   // Returns the offset into the shared memory where the frame data begins.
   size_t shared_memory_offset() const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns backing DmaBuf file descriptor for given |plane|, if present, or
   // -1 if not.
   // TODO(mcasas): Rename to DmabufFd() to comply with Style Guide.
@@ -519,7 +519,7 @@ class MEDIA_EXPORT VideoFrame : public b
   base::SharedMemoryHandle shared_memory_handle_;
   size_t shared_memory_offset_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Dmabufs for each plane. If set, this frame has DmaBuf backing in some way.
   base::ScopedFD dmabuf_fds_[kMaxPlanes];
 #endif
