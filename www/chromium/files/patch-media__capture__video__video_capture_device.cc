--- media/capture/video/video_capture_device.cc.orig	2015-10-14 17:57:48.996214000 +0200
+++ media/capture/video/video_capture_device.cc	2015-10-14 18:00:26.654041000 +0200
@@ -9,6 +9,10 @@
 
 namespace media {
 
+const std::string VideoCaptureDevice::Name::GetModel() const {
+  return "";
+}
+
 const std::string VideoCaptureDevice::Name::GetNameAndModel() const {
   const std::string model_id = GetModel();
   if (model_id.empty())
@@ -26,7 +30,7 @@
     : device_name_(name), unique_id_(id) {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 VideoCaptureDevice::Name::Name(const std::string& name,
                                const std::string& id,
                                const CaptureApiType api_type)
@@ -73,7 +77,7 @@
 VideoCaptureDevice::Name::~Name() {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char* VideoCaptureDevice::Name::GetCaptureApiTypeString() const {
   switch (capture_api_type()) {
     case V4L2_SINGLE_PLANE:
