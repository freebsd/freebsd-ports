--- media/video/capture/video_capture_device.cc.orig	2015-06-19 21:26:28 UTC
+++ media/video/capture/video_capture_device.cc
@@ -9,6 +9,10 @@
 
 namespace media {
 
+const std::string VideoCaptureDevice::Name::GetModel() const {
+  return "";
+}
+
 const std::string VideoCaptureDevice::Name::GetNameAndModel() const {
   const std::string model_id = GetModel();
   if (model_id.empty())
@@ -24,7 +28,7 @@
 VideoCaptureDevice::Name::Name(const std::string& name, const std::string& id)
     : device_name_(name), unique_id_(id) {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 VideoCaptureDevice::Name::Name(const std::string& name,
                                const std::string& id,
                                const CaptureApiType api_type)
@@ -69,7 +73,7 @@
 
 VideoCaptureDevice::Name::~Name() {}
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char* VideoCaptureDevice::Name::GetCaptureApiTypeString() const {
   switch (capture_api_type()) {
     case V4L2_SINGLE_PLANE:
