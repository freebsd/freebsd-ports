--- src/media/video/v4l2/video_device_monitor_impl.cpp.orig	2016-05-10 20:45:50 UTC
+++ src/media/video/v4l2/video_device_monitor_impl.cpp
@@ -24,7 +24,10 @@
 #include <cerrno>
 #include <cstdio>
 #include <cstring>
+#if !defined(__FreeBSD__)
 #include <libudev.h>
+#define HAVE_UDEV
+#endif
 #include <mutex>
 #include <sstream>
 #include <stdexcept> // for std::runtime_error
@@ -72,24 +75,31 @@ class VideoDeviceMonitorImpl {
         std::thread thread_;
         mutable std::mutex mutex_;
 
+#if defined(HAVE_UDEV)
         udev *udev_;
         udev_monitor *udev_mon_;
+#endif
         bool probing_;
 };
 
+#if defined(HAVE_UDEV)
 static int is_v4l2(struct udev_device *dev)
 {
     const char *version = udev_device_get_property_value(dev, "ID_V4L_VERSION");
     /* we do not support video4linux 1 */
     return version and strcmp(version, "1");
 }
+#endif
 
 VideoDeviceMonitorImpl::VideoDeviceMonitorImpl(VideoDeviceMonitor* monitor) :
     monitor_(monitor),
     thread_(), mutex_(),
+#if defined(HAVE_UDEV)
     udev_(0), udev_mon_(0),
+#endif
     probing_(false)
 {
+#if defined(HAVE_UDEV)
     udev_list_entry *devlist;
     udev_enumerate *devenum;
 
@@ -149,15 +159,16 @@ udev_failed:
         udev_unref(udev_);
     udev_mon_ = NULL;
     udev_ = NULL;
+#endif
 
     /* fallback : go through /dev/video* */
-    for (int idx = 0;; ++idx) {
+    for (int idx = 0; idx<16; ++idx) {
         std::stringstream ss;
         ss << "/dev/video" << idx;
         try {
             monitor_->addDevice(ss.str());
         } catch (const std::runtime_error &e) {
-            RING_ERR("%s", e.what());
+            RING_ERR("%s (YURI exit from constructor)", e.what());
             return;
         }
     }
@@ -174,14 +185,17 @@ VideoDeviceMonitorImpl::~VideoDeviceMoni
     probing_ = false;
     if (thread_.joinable())
         thread_.join();
+#if defined(HAVE_UDEV)
     if (udev_mon_)
         udev_monitor_unref(udev_mon_);
     if (udev_)
         udev_unref(udev_);
+#endif
 }
 
 void VideoDeviceMonitorImpl::run()
 {
+#if defined(HAVE_UDEV)
     if (!udev_mon_) {
         probing_ = false;
         return;
@@ -236,6 +250,7 @@ void VideoDeviceMonitorImpl::run()
                 return;
         }
     }
+#endif
 }
 
 VideoDeviceMonitor::VideoDeviceMonitor() :
