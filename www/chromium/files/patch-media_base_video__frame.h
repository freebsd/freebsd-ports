--- media/base/video_frame.h.orig	2017-06-05 19:03:08 UTC
+++ media/base/video_frame.h
@@ -62,7 +62,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Pixels are backed by Shared Memory.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -188,7 +188,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       uint8_t* a_data,
       base::TimeDelta timestamp);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/Documentation/dma-buf-sharing.txt) with a
   // VideoFrame. The dmabuf fds are dup()ed on creation, so that the VideoFrame
@@ -338,7 +338,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // Returns the offset into the shared memory where the frame data begins.
   size_t shared_memory_offset() const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns backing DmaBuf file descriptor for given |plane|, if present, or
   // -1 if not.
   int DmabufFd(size_t plane) const;
@@ -531,7 +531,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   base::SharedMemoryHandle shared_memory_handle_;
   size_t shared_memory_offset_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Dmabufs for each plane. If set, this frame has DmaBuf backing in some way.
   base::ScopedFD dmabuf_fds_[kMaxPlanes];
 #endif
