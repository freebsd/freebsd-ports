--- media/capture/video/video_capture_device_factory.cc.orig	2016-05-11 19:02:23 UTC
+++ media/capture/video/video_capture_device_factory.cc
@@ -17,6 +17,10 @@ namespace media {
 // static
 scoped_ptr<VideoCaptureDeviceFactory> VideoCaptureDeviceFactory::CreateFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
+#if defined(OS_BSD)
+  return scoped_ptr<VideoCaptureDeviceFactory>(new
+      media::FakeVideoCaptureDeviceFactory());
+#else
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
   // Use a Fake or File Video Device Factory if the command line flags are
@@ -35,6 +39,7 @@ scoped_ptr<VideoCaptureDeviceFactory> Vi
     return scoped_ptr<VideoCaptureDeviceFactory>(
         CreateVideoCaptureDeviceFactory(ui_task_runner));
   }
+#endif
 }
 
 VideoCaptureDeviceFactory::VideoCaptureDeviceFactory() {
