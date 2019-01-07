--- media/base/video_frame.cc.orig	2018-12-03 21:17:03.000000000 +0100
+++ media/base/video_frame.cc	2018-12-13 23:34:19.884280000 +0100
@@ -66,7 +66,7 @@
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -82,7 +82,7 @@
 // static
 static bool IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -379,7 +379,7 @@
   return frame;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -502,7 +502,7 @@
     wrapping_frame->data_[i] = frame->data(i);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If there are any |dmabuf_fds_| plugged in, we should duplicate them.
   if (frame->storage_type() == STORAGE_DMABUFS) {
     wrapping_frame->dmabuf_fds_ = DuplicateFDs(frame->dmabuf_fds_);
@@ -839,7 +839,7 @@
   return shared_memory_offset_;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const std::vector<base::ScopedFD>& VideoFrame::DmabufFds() const {
   DCHECK_EQ(storage_type_, STORAGE_DMABUFS);
 
