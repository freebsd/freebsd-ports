--- media/capture/video/linux/video_capture_device_linux.cc.orig	2015-10-14 17:46:45.617486000 +0200
+++ media/capture/video/linux/video_capture_device_linux.cc	2015-10-14 21:44:58.276861000 +0200
@@ -43,6 +43,7 @@
 
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
+#if !defined(OS_FREEBSD)
 VideoCapturePixelFormat
 VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(uint32 v4l2_fourcc) {
   return V4L2CaptureDelegate::V4l2FourCcToChromiumPixelFormat(v4l2_fourcc);
@@ -54,6 +55,7 @@
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif  // !OS_FREEBSD
 
 const std::string VideoCaptureDevice::Name::GetModel() const {
   // |unique_id| is of the form "/dev/video2".  |file_name| is "video2".
@@ -88,6 +90,7 @@
   v4l2_thread_.Stop();
 }
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     scoped_ptr<VideoCaptureDevice::Client> client) {
@@ -130,6 +133,13 @@
         base::Bind(&V4L2CaptureDelegate::SetRotation, capture_impl_, rotation));
   }
 }
+#else  // !OS_FREEBSD
+void VideoCaptureDeviceLinux::AllocateAndStart(
+    const VideoCaptureParams& params,
+    scoped_ptr<VideoCaptureDevice::Client> client) {}
+void VideoCaptureDeviceLinux::StopAndDeAllocate() {}
+void VideoCaptureDeviceLinux::SetRotation(int rotation) {}
+#endif  // !OS_FREEBSD
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(int frequency) {
