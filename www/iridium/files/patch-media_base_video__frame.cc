--- media/base/video_frame.cc.orig	2024-08-27 06:28:16 UTC
+++ media/base/video_frame.cc
@@ -83,7 +83,7 @@ std::string VideoFrame::StorageTypeToString(
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -98,7 +98,7 @@ std::string VideoFrame::StorageTypeToString(
 // static
 bool VideoFrame::IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -396,7 +396,7 @@ VideoFrame::CreateFrameForGpuMemoryBufferOrMappableSII
                            : shared_image->GetStrideForVideoFrame(i);
   }
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool is_native_buffer =
       gpu_memory_buffer
           ? (gpu_memory_buffer->GetType() != gfx::SHARED_MEMORY_BUFFER)
@@ -817,7 +817,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapExternalGpuM
   return frame;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -1528,7 +1528,7 @@ scoped_refptr<gpu::ClientSharedImage> VideoFrame::shar
                         : shared_images_[texture_index];
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 size_t VideoFrame::NumDmabufFds() const {
   if (wrapped_frame_) {
     return wrapped_frame_->NumDmabufFds();
