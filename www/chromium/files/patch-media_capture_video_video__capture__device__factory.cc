--- media/capture/video/video_capture_device_factory.cc.orig	2016-08-13 01:27:17.328942000 +0300
+++ media/capture/video/video_capture_device_factory.cc	2016-08-13 01:16:43.725148000 +0300
@@ -18,6 +18,10 @@
 std::unique_ptr<VideoCaptureDeviceFactory>
 VideoCaptureDeviceFactory::CreateFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
+#if defined(OS_BSD)
+  return std::unique_ptr<VideoCaptureDeviceFactory>(
+          new media::FakeVideoCaptureDeviceFactory());
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
@@ -56,7 +61,7 @@
   callback.Run(std::move(device_names));
 }

-#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && \
+#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_BSD) && !defined(OS_ANDROID) && \
     !defined(OS_WIN)
 // static
 VideoCaptureDeviceFactory*
