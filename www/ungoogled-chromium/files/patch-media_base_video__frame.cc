--- media/base/video_frame.cc.orig	2026-06-12 07:58:04 UTC
+++ media/base/video_frame.cc
@@ -86,7 +86,7 @@ std::string VideoFrame::StorageTypeToString(
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -418,7 +418,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapMappableShar
         plane_size.width() * VideoFrame::BytesPerElement(*format, plane);
   }
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool is_native_buffer = !shared_image->IsSharedMemoryForVideoFrame();
   if (is_native_buffer) {
     const auto gmb_handle = shared_image->CloneGpuMemoryBufferHandle();
@@ -682,7 +682,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapExternalYuva
   return frame;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -1416,7 +1416,7 @@ scoped_refptr<gpu::ClientSharedImage> VideoFrame::shar
   return wrapped_frame_ ? wrapped_frame_->shared_image() : shared_image_;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 size_t VideoFrame::NumDmabufFds() const {
   if (wrapped_frame_) {
     return wrapped_frame_->NumDmabufFds();
