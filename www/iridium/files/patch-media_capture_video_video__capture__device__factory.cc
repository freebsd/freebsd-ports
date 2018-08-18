--- media/capture/video/video_capture_device_factory.cc.orig	2018-06-13 00:10:20.000000000 +0200
+++ media/capture/video/video_capture_device_factory.cc	2018-07-20 21:26:51.824846000 +0200
@@ -21,6 +21,10 @@
     gpu::GpuMemoryBufferManager* gpu_buffer_manager,
     MojoJpegDecodeAcceleratorFactoryCB jda_factory,
     MojoJpegEncodeAcceleratorFactoryCB jea_factory) {
+#if defined(OS_BSD)
+   return std::unique_ptr<VideoCaptureDeviceFactory>(
+           new media::FakeVideoCaptureDeviceFactory());
+#else
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
   // Use a Fake or File Video Device Factory if the command line flags are
@@ -47,6 +51,7 @@
                                         std::move(jda_factory),
                                         std::move(jea_factory)));
   }
+#endif
 }
 
 VideoCaptureDeviceFactory::VideoCaptureDeviceFactory() {
@@ -56,7 +61,7 @@
 VideoCaptureDeviceFactory::~VideoCaptureDeviceFactory() = default;
 
 #if !defined(OS_MACOSX) && !defined(OS_LINUX) && !defined(OS_ANDROID) && \
-    !defined(OS_WIN)
+    !defined(OS_WIN) && !defined(OS_BSD)
 // static
 VideoCaptureDeviceFactory*
 VideoCaptureDeviceFactory::CreateVideoCaptureDeviceFactory(
