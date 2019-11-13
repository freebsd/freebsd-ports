--- media/base/video_frame.h.orig	2019-10-21 19:06:36 UTC
+++ media/base/video_frame.h
@@ -39,9 +39,9 @@
 #include "base/mac/scoped_cftyperef.h"
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace media {
 
@@ -76,7 +76,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Backed by unsafe (writable) shared memory.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -229,7 +229,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       uint8_t* a_data,
       base::TimeDelta timestamp);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -444,7 +444,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // mailbox, the caller must wait for the included sync point.
   const gpu::MailboxHolder& mailbox_holder(size_t texture_index) const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns a vector containing the backing DmaBufs for this frame. The number
   // of returned DmaBufs will be equal or less than the number of planes of
   // the frame. If there are less, this means that the last FD contains the
@@ -630,7 +630,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   base::UnsafeSharedMemoryRegion owned_shm_region_;
   base::WritableSharedMemoryMapping owned_shm_mapping_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   class DmabufHolder;
 
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either
