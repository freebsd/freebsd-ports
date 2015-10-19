--- media/capture/video/video_capture_device_factory.cc.orig	2015-10-14 18:11:45.655658000 +0200
+++ media/capture/video/video_capture_device_factory.cc	2015-10-14 18:13:09.785092000 +0200
@@ -14,6 +14,10 @@
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
@@ -32,6 +36,7 @@
     return scoped_ptr<VideoCaptureDeviceFactory>(
         CreateVideoCaptureDeviceFactory(ui_task_runner));
   }
+#endif
 }
 
 VideoCaptureDeviceFactory::VideoCaptureDeviceFactory() {
