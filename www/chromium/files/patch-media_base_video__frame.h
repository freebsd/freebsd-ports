--- media/base/video_frame.h.orig	2025-03-05 08:14:56 UTC
+++ media/base/video_frame.h
@@ -42,7 +42,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/hdr_metadata.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -88,7 +88,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Backed by read-only shared memory.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     STORAGE_DMABUFS = 5,  // Each plane is stored into a DmaBuf.
 #endif
     STORAGE_GPU_MEMORY_BUFFER = 6,
@@ -424,7 +424,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       ReleaseMailboxAndGpuMemoryBufferCB mailbox_holder_and_gmb_release_cb,
       base::TimeDelta timestamp);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -734,7 +734,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // wait for the included sync point.
   scoped_refptr<gpu::ClientSharedImage> shared_image() const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The number of DmaBufs will be equal or less than the number of planes of
   // the frame. If there are less, this means that the last FD contains the
   // remaining planes. Should be > 0 for STORAGE_DMABUFS.
@@ -963,7 +963,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // GpuMemoryBuffers. Clients will set this flag while creating a VideoFrame.
   bool is_mappable_si_enabled_ = false;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either
   // equal or less than the number of planes of the frame. If it is less, then
   // the memory area represented by the last FD contains the remaining planes.
