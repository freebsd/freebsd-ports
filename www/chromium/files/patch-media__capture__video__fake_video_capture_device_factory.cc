--- media/capture/video/fake_video_capture_device_factory.cc.orig	2015-10-14 11:08:16.489018000 -0400
+++ media/capture/video/fake_video_capture_device_factory.cc	2015-10-14 11:09:19.850751000 -0400
@@ -51,7 +51,7 @@
   for (int n = 0; n < number_of_devices_; ++n) {
     VideoCaptureDevice::Name name(base::StringPrintf("fake_device_%d", n),
                                   base::StringPrintf("/dev/video%d", n)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                       ,
                                   VideoCaptureDevice::Name::V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
