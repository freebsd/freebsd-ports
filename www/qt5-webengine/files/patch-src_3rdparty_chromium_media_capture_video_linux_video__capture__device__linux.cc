--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc.orig	2019-03-01 17:04:22 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc
@@ -15,7 +15,7 @@
 
 #if defined(OS_OPENBSD)
 #include <sys/videoio.h>
-#else
+#elif !defined(OS_FREEBSD)
 #include <linux/videodev2.h>
 #include <linux/version.h>
 #endif
@@ -31,17 +31,18 @@ int TranslatePowerLineFrequencyToV4L2(PowerLineFrequen
     case PowerLineFrequency::FREQUENCY_60HZ:
       return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
     default:
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
+//#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
       // If we have no idea of the frequency, at least try and set it to AUTO.
       return V4L2_CID_POWER_LINE_FREQUENCY_AUTO;
-#else
-      return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
-#endif
+//#else
+//      return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
+//#endif
   }
 }
 
 }  // namespace
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -55,6 +56,7 @@ std::vector<uint32_t> VideoCaptureDeviceLinux::GetList
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 VideoCaptureDeviceLinux::VideoCaptureDeviceLinux(
     scoped_refptr<V4L2CaptureDevice> v4l2,
@@ -73,6 +75,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDeviceLinux() {
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
+#if !defined(OS_FREEBSD)
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -100,9 +103,11 @@ void VideoCaptureDeviceLinux::AllocateAndStart(
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
@@ -112,6 +117,7 @@ void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   v4l2_thread_.Stop();
 
   capture_impl_ = nullptr;
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::TakePhoto(TakePhotoCallback callback) {
@@ -154,11 +160,13 @@ void VideoCaptureDeviceLinux::SetPhotoOptions(
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
