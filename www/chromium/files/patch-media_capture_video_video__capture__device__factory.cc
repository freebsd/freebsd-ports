--- media/capture/video/video_capture_device_factory.cc.orig	2016-07-22 00:06:55.000000000 -0400
+++ media/capture/video/video_capture_device_factory.cc	2016-08-04 16:01:12.907434000 -0400
@@ -18,6 +18,10 @@
 std::unique_ptr<VideoCaptureDeviceFactory>
 VideoCaptureDeviceFactory::CreateFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
+#if defined(OS_BSD)
+  return std::unique_ptr<VideoCaptureDeviceFactory>(new
+      media::FakeVideoCaptureDeviceFactory());
+#else
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
   // Use a Fake or File Video Device Factory if the command line flags are
@@ -36,6 +40,7 @@
     return std::unique_ptr<VideoCaptureDeviceFactory>(
         CreateVideoCaptureDeviceFactory(ui_task_runner));
   }
+#endif
 }
 
 VideoCaptureDeviceFactory::VideoCaptureDeviceFactory() {
