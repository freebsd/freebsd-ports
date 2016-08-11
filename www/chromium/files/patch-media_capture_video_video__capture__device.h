--- media/capture/video/video_capture_device.h.orig	2016-05-11 19:02:23 UTC
+++ media/capture/video/video_capture_device.h
@@ -51,7 +51,7 @@ class MEDIA_EXPORT VideoCaptureDevice {
     Name();
     Name(const std::string& name, const std::string& id);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Linux/CrOS targets Capture Api type: it can only be set on construction.
     enum CaptureApiType {
       V4L2_SINGLE_PLANE,
@@ -82,7 +82,7 @@ class MEDIA_EXPORT VideoCaptureDevice {
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     Name(const std::string& name,
          const std::string& id,
          const CaptureApiType api_type);
@@ -119,7 +119,7 @@ class MEDIA_EXPORT VideoCaptureDevice {
     bool operator<(const Name& other) const { return unique_id_ < other.id(); }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     CaptureApiType capture_api_type() const {
       return capture_api_class_.capture_api_type();
     }
@@ -143,7 +143,7 @@ class MEDIA_EXPORT VideoCaptureDevice {
     std::string device_name_;
     std::string unique_id_;
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     // This class wraps the CaptureApiType to give it a by default value if not
     // initialized.
     class CaptureApiClass {
