--- media/base/video_frame.h.orig	2020-07-07 21:58:16 UTC
+++ media/base/video_frame.h
@@ -40,9 +40,9 @@
 #include "base/mac/scoped_cftyperef.h"
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace gfx {
 class GpuMemoryBuffer;
@@ -81,7 +81,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Backed by unsafe (writable) shared memory.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -245,7 +245,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       ReleaseMailboxCB mailbox_holder_release_cb,
       base::TimeDelta timestamp);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -485,7 +485,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // mailbox, the caller must wait for the included sync point.
   const gpu::MailboxHolder& mailbox_holder(size_t texture_index) const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns a vector containing the backing DmaBufs for this frame. The number
   // of returned DmaBufs will be equal or less than the number of planes of
   // the frame. If there are less, this means that the last FD contains the
@@ -663,7 +663,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // GPU memory buffer, if this frame is STORAGE_GPU_MEMORY_BUFFER.
   std::unique_ptr<gfx::GpuMemoryBuffer> gpu_memory_buffer_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   class DmabufHolder;
 
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either
