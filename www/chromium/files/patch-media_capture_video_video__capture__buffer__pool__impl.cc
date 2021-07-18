--- media/capture/video/video_capture_buffer_pool_impl.cc.orig	2021-04-14 18:41:05 UTC
+++ media/capture/video/video_capture_buffer_pool_impl.cc
@@ -68,7 +68,7 @@ VideoCaptureBufferPoolImpl::CreateSharedMemoryViaRawFi
     int buffer_id) {
 // This requires platforms where base::SharedMemoryHandle is backed by a
 // file descriptor.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::AutoLock lock(lock_);
 
   VideoCaptureBufferTracker* tracker = GetTracker(buffer_id);
