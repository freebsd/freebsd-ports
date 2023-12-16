--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device.h.orig	2022-02-07 13:39:41 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device.h
@@ -21,7 +21,7 @@ class CAPTURE_EXPORT V4L2CaptureDevice
  public:
   virtual int open(const char* device_name, int flags) = 0;
   virtual int close(int fd) = 0;
-  virtual int ioctl(int fd, int request, void* argp) = 0;
+  virtual int ioctl(int fd, unsigned long request, void* argp) = 0;
   virtual void* mmap(void* start,
                      size_t length,
                      int prot,
