--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.h
@@ -52,7 +52,7 @@ class CAPTURE_EXPORT VideoCaptureDeviceFactoryLinux
 
  private:
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(fd, ...)).
-  int DoIoctl(int fd, int request, void* argp);
+  int DoIoctl(int fd, unsigned int request, void* argp);
 
   VideoCaptureControlSupport GetControlSupport(int fd);
   bool GetControlSupport(int fd, int control_id);
