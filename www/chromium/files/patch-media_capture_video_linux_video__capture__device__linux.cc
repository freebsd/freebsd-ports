--- media/capture/video/linux/video_capture_device_linux.cc.orig	2017-04-19 19:06:35 UTC
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -21,6 +21,7 @@
 
 namespace media {
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -34,6 +35,7 @@ std::list<uint32_t> VideoCaptureDeviceLi
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 VideoCaptureDeviceLinux::VideoCaptureDeviceLinux(
     const VideoCaptureDeviceDescriptor& device_descriptor)
@@ -47,6 +49,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDe
   v4l2_thread_.Stop();
 }
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
@@ -74,7 +77,13 @@ void VideoCaptureDeviceLinux::AllocateAn
     v4l2_thread_.task_runner()->PostTask(FROM_HERE, request);
   photo_requests_queue_.clear();
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::AllocateAndStart(
+    const VideoCaptureParams& params,
+    std::unique_ptr<VideoCaptureDevice::Client> client) {}
+#endif // !defined(OS_FREEBSD)
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -123,7 +132,11 @@ void VideoCaptureDeviceLinux::SetPhotoOp
   }
   v4l2_thread_.task_runner()->PostTask(FROM_HERE, std::move(functor));
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::StopAndDeAllocate() {}
+#endif // !defined(OS_FREEBSD)
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.task_runner()->PostTask(
@@ -131,6 +144,9 @@ void VideoCaptureDeviceLinux::SetRotatio
         base::Bind(&V4L2CaptureDelegate::SetRotation, capture_impl_, rotation));
   }
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::SetRotation(int rotation) {}
+#endif // !defined(OS_FREEBSD)
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(
