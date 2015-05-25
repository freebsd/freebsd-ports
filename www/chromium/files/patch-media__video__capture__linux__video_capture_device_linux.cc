--- media/video/capture/linux/video_capture_device_linux.cc.orig	2015-05-21 14:00:42.807667000 -0400
+++ media/video/capture/linux/video_capture_device_linux.cc	2015-05-21 14:05:22.707732000 -0400
@@ -44,6 +44,7 @@
 
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
+#if !defined(OS_FREEBSD)
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
     uint32 v4l2_fourcc) {
   return V4L2CaptureDelegate::V4l2FourCcToChromiumPixelFormat(v4l2_fourcc);
@@ -55,6 +56,7 @@
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif
 
 const std::string VideoCaptureDevice::Name::GetModel() const {
   // |unique_id| is of the form "/dev/video2".  |file_name| is "video2".
@@ -90,6 +92,7 @@
   v4l2_thread_.Stop();
 }
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     scoped_ptr<VideoCaptureDevice::Client> client) {
@@ -132,6 +135,7 @@
                               capture_impl_, rotation));
   }
 }
+#endif
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(int frequency) {
