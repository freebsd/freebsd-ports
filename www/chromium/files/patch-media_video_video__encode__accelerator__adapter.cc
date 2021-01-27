--- media/video/video_encode_accelerator_adapter.cc.orig	2021-01-22 12:10:35 UTC
+++ media/video/video_encode_accelerator_adapter.cc
@@ -40,7 +40,7 @@ VideoEncodeAccelerator::Config SetUpVeaConfig(
       opts.bitrate.value_or(opts.frame_size.width() * opts.frame_size.height() *
                             kVEADefaultBitratePerPixel));
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (storage_type == VideoFrame::STORAGE_DMABUFS ||
       storage_type == VideoFrame::STORAGE_GPU_MEMORY_BUFFER) {
     config.storage_type = VideoEncodeAccelerator::Config::StorageType::kDmabuf;
@@ -269,7 +269,7 @@ void VideoEncodeAcceleratorAdapter::EncodeOnAccelerato
     return;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   const bool is_same_storage_type = storage_type_ == frame->storage_type();
 #else
