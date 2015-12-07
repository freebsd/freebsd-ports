--- media/capture/video/linux/video_capture_device_linux.cc.orig	2015-10-21 18:00:38.000000000 -0400
+++ media/capture/video/linux/video_capture_device_linux.cc	2015-10-23 12:49:31.985359000 -0400
@@ -43,6 +43,7 @@
 
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
+#if !defined(OS_FREEBSD)
 VideoPixelFormat
 VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(uint32 v4l2_fourcc) {
   return V4L2CaptureDelegate::V4l2FourCcToChromiumPixelFormat(v4l2_fourcc);
@@ -54,6 +55,7 @@
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif  // !defined(OS_FREEBSD)
 
 const std::string VideoCaptureDevice::Name::GetModel() const {
   // |unique_id| is of the form "/dev/video2".  |file_name| is "video2".
@@ -91,6 +93,7 @@
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     scoped_ptr<VideoCaptureDevice::Client> client) {
+#if !defined(OS_FREEBSD)
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -110,9 +113,11 @@
                  params.requested_format.frame_size.width(),
                  params.requested_format.frame_size.height(),
                  params.requested_format.frame_rate, base::Passed(&client)));
+#endif
 }
 
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
+#if !defined(OS_FREEBSD)
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
   v4l2_thread_.message_loop()->PostTask(
@@ -121,8 +126,10 @@
   v4l2_thread_.Stop();
 
   capture_impl_ = NULL;
+#endif
 }
 
+#if !defined(OS_FREEBSD)
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.message_loop()->PostTask(
@@ -130,6 +137,7 @@
         base::Bind(&V4L2CaptureDelegate::SetRotation, capture_impl_, rotation));
   }
 }
+#endif  // !defined(OS_FREEBSD)
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(int frequency) {
