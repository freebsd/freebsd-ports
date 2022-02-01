--- media/base/video_frame.cc.orig	2021-12-14 11:45:07 UTC
+++ media/base/video_frame.cc
@@ -73,7 +73,7 @@ std::string VideoFrame::StorageTypeToString(
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -90,7 +90,7 @@ std::string VideoFrame::StorageTypeToString(
 // static
 bool VideoFrame::IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -278,7 +278,7 @@ static absl::optional<VideoFrameLayout> GetDefaultLayo
   return VideoFrameLayout::CreateWithPlanes(format, coded_size, planes);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // This class allows us to embed a vector<ScopedFD> into a scoped_refptr, and
 // thus to have several VideoFrames share the same set of DMABUF FDs.
 class VideoFrame::DmabufHolder
@@ -296,7 +296,7 @@ class VideoFrame::DmabufHolder
   friend class base::RefCountedThreadSafe<DmabufHolder>;
   ~DmabufHolder() = default;
 };
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // static
 bool VideoFrame::IsValidConfig(VideoPixelFormat format,
@@ -617,7 +617,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapExternalGpuM
   for (size_t i = 0; i < num_planes; ++i)
     planes[i].stride = gpu_memory_buffer->stride(i);
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (gpu_memory_buffer->GetType() == gfx::NATIVE_PIXMAP) {
     const auto gmb_handle = gpu_memory_buffer->CloneHandle();
     if (gmb_handle.is_null() ||
@@ -663,7 +663,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapExternalGpuM
   return frame;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -887,7 +887,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapVideoFrame(
     }
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   DCHECK(frame->dmabuf_fds_);
   // If there are any |dmabuf_fds_| plugged in, we should refer them too.
   wrapping_frame->dmabuf_fds_ = frame->dmabuf_fds_;
@@ -1253,7 +1253,7 @@ const gpu::MailboxHolder& VideoFrame::mailbox_holder(
                         : mailbox_holders_[texture_index];
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const std::vector<base::ScopedFD>& VideoFrame::DmabufFds() const {
   DCHECK_EQ(storage_type_, STORAGE_DMABUFS);
 
@@ -1365,7 +1365,7 @@ VideoFrame::VideoFrame(const VideoFrameLayout& layout,
       storage_type_(storage_type),
       visible_rect_(Intersection(visible_rect, gfx::Rect(layout.coded_size()))),
       natural_size_(natural_size),
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       dmabuf_fds_(base::MakeRefCounted<DmabufHolder>()),
 #endif
       timestamp_(timestamp),
