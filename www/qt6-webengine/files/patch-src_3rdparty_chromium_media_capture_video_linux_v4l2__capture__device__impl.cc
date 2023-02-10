--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device_impl.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device_impl.cc
@@ -22,7 +22,7 @@ int V4L2CaptureDeviceImpl::close(int fd) {
   return ::close(fd);
 }
 
-int V4L2CaptureDeviceImpl::ioctl(int fd, int request, void* argp) {
+int V4L2CaptureDeviceImpl::ioctl(int fd, unsigned long request, void* argp) {
   return ::ioctl(fd, request, argp);
 }
 
