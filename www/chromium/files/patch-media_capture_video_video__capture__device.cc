--- media/capture/video/video_capture_device.cc.orig	2016-05-11 19:02:23 UTC
+++ media/capture/video/video_capture_device.cc
@@ -13,6 +13,10 @@
 
 namespace media {
 
+const std::string VideoCaptureDevice::Name::GetModel() const {
+  return "";
+}
+
 // TODO(msu.koo): http://crbug.com/532272, remove checking the switch in favour
 // of deferring GetModel() call to the actual VideoCaptureDevice object.
 const std::string VideoCaptureDevice::Name::GetNameAndModel() const {
@@ -35,7 +39,7 @@ VideoCaptureDevice::Name::Name(const std
     : device_name_(name), unique_id_(id) {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 VideoCaptureDevice::Name::Name(const std::string& name,
                                const std::string& id,
                                const CaptureApiType api_type)
@@ -82,7 +86,7 @@ VideoCaptureDevice::Name::Name(const std
 VideoCaptureDevice::Name::~Name() {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char* VideoCaptureDevice::Name::GetCaptureApiTypeString() const {
   switch (capture_api_type()) {
     case V4L2_SINGLE_PLANE:
