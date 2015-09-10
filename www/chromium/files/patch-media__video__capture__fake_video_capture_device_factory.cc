--- media/video/capture/fake_video_capture_device_factory.cc.orig	2015-06-19 21:21:37 UTC
+++ media/video/capture/fake_video_capture_device_factory.cc
@@ -48,7 +48,7 @@
   for (int n = 0; n < number_of_devices_; ++n) {
     VideoCaptureDevice::Name name(base::StringPrintf("fake_device_%d", n),
                                   base::StringPrintf("/dev/video%d", n)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                   , VideoCaptureDevice::Name::V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
                                   , VideoCaptureDevice::Name::AVFOUNDATION
