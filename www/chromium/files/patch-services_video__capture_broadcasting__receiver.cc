--- services/video_capture/broadcasting_receiver.cc.orig	2021-12-31 00:57:38 UTC
+++ services/video_capture/broadcasting_receiver.cc
@@ -28,7 +28,7 @@ void CloneSharedBufferHandle(const mojo::ScopedSharedB
 void CloneSharedBufferToRawFileDescriptorHandle(
     const mojo::ScopedSharedBufferHandle& source,
     media::mojom::VideoBufferHandlePtr* target) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // |source| is unwrapped to a |PlatformSharedMemoryRegion|, from whence a file
   // descriptor can be extracted which is then mojo-wrapped.
   base::subtle::PlatformSharedMemoryRegion platform_region =
@@ -240,7 +240,7 @@ void BroadcastingReceiver::BufferContext::
     ConvertRawFileDescriptorToSharedBuffer() {
   DCHECK(buffer_handle_->is_shared_memory_via_raw_file_descriptor());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // The conversion unwraps the descriptor from its mojo handle to the raw file
   // descriptor (ie, an int). This is used to create a
   // PlatformSharedMemoryRegion which is then wrapped as a
