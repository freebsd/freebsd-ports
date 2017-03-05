--- media/base/video_frame.cc.orig	2017-02-02 02:02:55 UTC
+++ media/base/video_frame.cc
@@ -53,7 +53,7 @@ static std::string StorageTypeToString(
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -69,7 +69,7 @@ static std::string StorageTypeToString(
 // static
 static bool IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -323,7 +323,7 @@ scoped_refptr<VideoFrame> VideoFrame::Wr
   return frame;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     VideoPixelFormat format,
@@ -435,7 +435,7 @@ scoped_refptr<VideoFrame> VideoFrame::Wr
     wrapping_frame->data_[i] = frame->data(i);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If there are any |dmabuf_fds_| plugged in, we should duplicate them.
   if (frame->storage_type() == STORAGE_DMABUFS) {
     std::vector<int> original_fds;
@@ -720,7 +720,7 @@ size_t VideoFrame::shared_memory_offset(
   return shared_memory_offset_;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int VideoFrame::dmabuf_fd(size_t plane) const {
   DCHECK_EQ(storage_type_, STORAGE_DMABUFS);
   DCHECK(IsValidPlane(plane, format_));
