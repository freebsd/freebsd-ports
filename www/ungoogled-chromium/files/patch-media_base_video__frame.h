--- media/base/video_frame.h.orig	2024-11-16 12:20:41 UTC
+++ media/base/video_frame.h
@@ -50,7 +50,7 @@
 #include "base/apple/scoped_cftyperef.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -109,7 +109,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Backed by read-only shared memory.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -240,7 +240,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       base::TimeDelta timestamp,
       bool zero_initialize_memory);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Wraps RegisteredMailboxFrameConverter mailbox with a VideoFrame. This is
   // used only by ChromeOS/Linux's out-of-process video decoder.
   // |mailbox_holder_release_cb| will be called with a sync token as the
@@ -386,7 +386,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       ReleaseMailboxAndGpuMemoryBufferCB mailbox_holder_and_gmb_release_cb,
       base::TimeDelta timestamp);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -551,7 +551,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // visible_data() etc.
   bool IsMappable() const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns true if `frame` has `oopvd_mailbox`.
   bool HasOOPVDMailbox() const;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -717,7 +717,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // wait for the included sync point.
   scoped_refptr<gpu::ClientSharedImage> shared_image() const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the OOPVD mailbox set by `WrapOOPVDMailbox`.
   // Only valid to call if this is a NATIVE_TEXTURE frame. Before using the
   // mailbox, the caller must wait for the included sync point.
@@ -966,7 +966,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // VideoFrame.
   const uint8_t* data_[kMaxPlanes];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Native texture mailbox, if this frame HasOOPVDMailbox().
   gpu::Mailbox oopvd_mailbox_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -995,7 +995,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // GpuMemoryBuffers. Clients will set this flag while creating a VideoFrame.
   bool is_mappable_si_enabled_ = false;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either
   // equal or less than the number of planes of the frame. If it is less, then
