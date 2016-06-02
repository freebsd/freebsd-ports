--- src/media/video/v4l2/video_device_impl.cpp.orig	2016-05-10 20:45:50 UTC
+++ src/media/video/v4l2/video_device_impl.cpp
@@ -285,7 +285,7 @@ VideoV4l2Size::getRate(FrameRate rate) c
 {
     double r = rate.real();
     for (const auto& item : rates_) {
-        if (std::fabs(item.frame_rate.real() - r) < 0.0001d)
+        if (std::fabs(item.frame_rate.real() - r) < 0.0001f)
             return item;
     }
     return rates_.back();
