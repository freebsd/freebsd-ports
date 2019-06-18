--- media/capture/video/linux/video_capture_device_linux.cc.orig	2019-03-11 22:00:59 UTC
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -37,6 +37,7 @@ int TranslatePowerLineFrequencyToV4L2(PowerLineFrequen
 
 }  // namespace
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -50,6 +51,7 @@ std::vector<uint32_t> VideoCaptureDeviceLinux::GetList
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 VideoCaptureDeviceLinux::VideoCaptureDeviceLinux(
     scoped_refptr<V4L2CaptureDevice> v4l2,
@@ -68,6 +70,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDeviceLinux() {
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
+#if !defined(OS_FREEBSD)
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -95,9 +98,11 @@ void VideoCaptureDeviceLinux::AllocateAndStart(
   for (auto& request : photo_requests_queue_)
     v4l2_thread_.task_runner()->PostTask(FROM_HERE, std::move(request));
   photo_requests_queue_.clear();
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
+#if !defined(OS_FREEBSD)
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
   v4l2_thread_.task_runner()->PostTask(
@@ -107,6 +112,7 @@ void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   v4l2_thread_.Stop();
 
   capture_impl_ = nullptr;
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::TakePhoto(TakePhotoCallback callback) {
@@ -149,11 +155,13 @@ void VideoCaptureDeviceLinux::SetPhotoOptions(
 }
 
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
+#if !defined(OS_FREEBSD)
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.task_runner()->PostTask(
         FROM_HERE, base::BindOnce(&V4L2CaptureDelegate::SetRotation,
                                   capture_impl_->GetWeakPtr(), rotation));
   }
+#endif // !defined(OS_FREEBSD)
 }
 
 }  // namespace media
