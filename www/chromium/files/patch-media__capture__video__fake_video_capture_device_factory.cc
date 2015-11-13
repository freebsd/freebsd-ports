--- media/capture/video/fake_video_capture_device_factory.cc.orig	2015-10-14 17:33:35.934406000 +0200
+++ media/capture/video/fake_video_capture_device_factory.cc	2015-10-14 17:34:01.687650000 +0200
@@ -51,7 +51,7 @@
   for (int n = 0; n < number_of_devices_; ++n) {
     VideoCaptureDevice::Name name(base::StringPrintf("fake_device_%d", n),
                                   base::StringPrintf("/dev/video%d", n)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                       ,
                                   VideoCaptureDevice::Name::V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
