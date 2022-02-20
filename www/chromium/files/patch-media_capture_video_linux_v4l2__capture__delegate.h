--- media/capture/video/linux/v4l2_capture_delegate.h.orig	2022-02-07 13:39:41 UTC
+++ media/capture/video/linux/v4l2_capture_delegate.h
@@ -84,10 +84,10 @@ class CAPTURE_EXPORT V4L2CaptureDelegate final {
   // device file descriptor or (re)starting streaming, can fail but works after
   // retrying (https://crbug.com/670262). Returns false if the |request| ioctl
   // fails too many times.
-  bool RunIoctl(int request, void* argp);
+  bool RunIoctl(unsigned int request, void* argp);
 
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(device_fd_.get(), ...)).
-  int DoIoctl(int request, void* argp);
+  int DoIoctl(unsigned int request, void* argp);
 
   // Creates a mojom::RangePtr with the (min, max, current, step) values of the
   // control associated with |control_id|. Returns an empty Range otherwise.
