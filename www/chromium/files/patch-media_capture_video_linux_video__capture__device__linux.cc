--- media/capture/video/linux/video_capture_device_linux.cc.orig	2016-10-06 04:02:21.000000000 +0300
+++ media/capture/video/linux/video_capture_device_linux.cc	2016-10-13 09:50:59.750346000 +0300
@@ -21,6 +21,7 @@
 
 namespace media {
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -34,6 +35,7 @@
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 VideoCaptureDeviceLinux::VideoCaptureDeviceLinux(
     const VideoCaptureDeviceDescriptor& device_descriptor)
@@ -47,6 +49,7 @@
   v4l2_thread_.Stop();
 }
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
@@ -70,7 +73,13 @@
                  params.requested_format.frame_size.height(),
                  params.requested_format.frame_rate, base::Passed(&client)));
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
@@ -81,7 +90,11 @@
 
   capture_impl_ = NULL;
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::StopAndDeAllocate() {}
+#endif // !defined(OS_FREEBSD)
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.task_runner()->PostTask(
@@ -89,6 +102,9 @@
         base::Bind(&V4L2CaptureDelegate::SetRotation, capture_impl_, rotation));
   }
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::SetRotation(int rotation) {}
+#endif // !defined(OS_FREEBSD)
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(
