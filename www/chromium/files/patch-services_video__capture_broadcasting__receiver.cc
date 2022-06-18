--- services/video_capture/broadcasting_receiver.cc.orig	2022-06-17 14:20:10 UTC
+++ services/video_capture/broadcasting_receiver.cc
@@ -234,7 +234,7 @@ void BroadcastingReceiver::BufferContext::
     ConvertRawFileDescriptorToUnsafeShmemRegion() {
   DCHECK(buffer_handle_->is_shared_memory_via_raw_file_descriptor());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const size_t handle_size =
       buffer_handle_->get_shared_memory_via_raw_file_descriptor()
           ->shared_memory_size_in_bytes;
