--- media/capture/video/linux/fake_v4l2_impl.h.orig	2022-02-07 13:39:41 UTC
+++ media/capture/video/linux/fake_v4l2_impl.h
@@ -36,7 +36,7 @@ class CAPTURE_EXPORT FakeV4L2Impl : public V4L2Capture
   // Implementation of V4L2CaptureDevice interface:
   int open(const char* device_name, int flags) override;
   int close(int fd) override;
-  int ioctl(int fd, int request, void* argp) override;
+  int ioctl(int fd, unsigned long request, void* argp) override;
   void* mmap(void* start,
              size_t length,
              int prot,
