--- src/3rdparty/chromium/media/capture/video/video_capture_device.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/media/capture/video/video_capture_device.cc
@@ -35,7 +35,7 @@ VideoCaptureDevice::Name::Name(const std
     : device_name_(name), unique_id_(id) {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 VideoCaptureDevice::Name::Name(const std::string& name,
                                const std::string& id,
                                const CaptureApiType api_type)
@@ -82,7 +82,7 @@ VideoCaptureDevice::Name::Name(const std
 VideoCaptureDevice::Name::~Name() {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char* VideoCaptureDevice::Name::GetCaptureApiTypeString() const {
   switch (capture_api_type()) {
     case V4L2_SINGLE_PLANE:
