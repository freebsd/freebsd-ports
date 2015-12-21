--- media/capture/video/linux/video_capture_device_linux.cc.orig	2015-11-24 21:00:55.000000000 +0100
+++ media/capture/video/linux/video_capture_device_linux.cc	2015-12-05 22:01:43.229465000 +0100
@@ -41,6 +41,7 @@
   return true;
 }
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat
@@ -54,6 +55,7 @@
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 const std::string VideoCaptureDevice::Name::GetModel() const {
   // |unique_id| is of the form "/dev/video2".  |file_name| is "video2".
@@ -88,6 +90,7 @@
   v4l2_thread_.Stop();
 }
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     scoped_ptr<VideoCaptureDevice::Client> client) {
@@ -111,7 +114,13 @@
                  params.requested_format.frame_size.height(),
                  params.requested_format.frame_rate, base::Passed(&client)));
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::AllocateAndStart(
+    const VideoCaptureParams& params,
+    scoped_ptr<VideoCaptureDevice::Client> client) {}
+#endif // !defined(OS_FREEBSD)
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -122,7 +131,11 @@
 
   capture_impl_ = NULL;
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::StopAndDeAllocate() {}
+#endif // !defined(OS_FREEBSD)
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.message_loop()->PostTask(
@@ -130,6 +143,9 @@
         base::Bind(&V4L2CaptureDelegate::SetRotation, capture_impl_, rotation));
   }
 }
+#else // !defined(OS_FREEBSD)
+void VideoCaptureDeviceLinux::SetRotation(int rotation) {}
+#endif // !defined(OS_FREEBSD)
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(int frequency) {
