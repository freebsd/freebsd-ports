--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.h
@@ -87,10 +87,10 @@ class CAPTURE_EXPORT V4L2CaptureDelegate final {
   // device file descriptor or (re)starting streaming, can fail but works after
   // retrying (https://crbug.com/670262). Returns false if the |request| ioctl
   // fails too many times.
-  bool RunIoctl(int request, void* argp);
+  bool RunIoctl(unsigned int request, void* argp);
 
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(device_fd_.get(), ...)).
-  int DoIoctl(int request, void* argp);
+  int DoIoctl(unsigned int request, void* argp);
 
   // Check whether the control is controllable (and not changed automatically).
   bool IsControllableControl(int control_id);
