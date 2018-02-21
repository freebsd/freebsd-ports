--- media/capture/video/video_capture_device_factory.cc.orig	2017-12-15 02:04:21.000000000 +0100
+++ media/capture/video/video_capture_device_factory.cc	2017-12-24 17:18:54.671292000 +0100
@@ -19,6 +19,10 @@
 VideoCaptureDeviceFactory::CreateFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner,
     gpu::GpuMemoryBufferManager* gpu_buffer_manager) {
+#if defined(OS_BSD)
+   return std::unique_ptr<VideoCaptureDeviceFactory>(
+           new media::FakeVideoCaptureDeviceFactory());
+#else
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
   // Use a Fake or File Video Device Factory if the command line flags are
@@ -43,6 +47,7 @@
     return std::unique_ptr<VideoCaptureDeviceFactory>(
         CreateVideoCaptureDeviceFactory(ui_task_runner, gpu_buffer_manager));
   }
+#endif
 }
 
 VideoCaptureDeviceFactory::VideoCaptureDeviceFactory() {
@@ -52,7 +57,7 @@
 VideoCaptureDeviceFactory::~VideoCaptureDeviceFactory() {}
 
 #if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && \
-    !defined(OS_WIN)
+    !defined(OS_WIN) && !defined(OS_BSD)
 // static
 VideoCaptureDeviceFactory*
 VideoCaptureDeviceFactory::CreateVideoCaptureDeviceFactory(
