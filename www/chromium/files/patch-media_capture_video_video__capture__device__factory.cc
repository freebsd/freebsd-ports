--- media/capture/video/video_capture_device_factory.cc.orig	2017-06-05 19:03:08 UTC
+++ media/capture/video/video_capture_device_factory.cc
@@ -18,6 +18,10 @@ namespace media {
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
@@ -42,6 +46,7 @@ VideoCaptureDeviceFactory::CreateFactory(
     return std::unique_ptr<VideoCaptureDeviceFactory>(
         CreateVideoCaptureDeviceFactory(ui_task_runner));
   }
+#endif
 }
 
 VideoCaptureDeviceFactory::VideoCaptureDeviceFactory() {
@@ -50,7 +55,7 @@ VideoCaptureDeviceFactory::VideoCaptureDeviceFactory()
 
 VideoCaptureDeviceFactory::~VideoCaptureDeviceFactory() {}
 
-#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && \
+#if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_BSD) && !defined(OS_ANDROID) && \
     !defined(OS_WIN)
 // static
 VideoCaptureDeviceFactory*
