--- media/video/capture/video_capture_device.h.orig	2015-06-19 21:22:59 UTC
+++ media/video/capture/video_capture_device.h
@@ -41,7 +41,7 @@
     Name();
     Name(const std::string& name, const std::string& id);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Linux/CrOS targets Capture Api type: it can only be set on construction.
     enum CaptureApiType {
       V4L2_SINGLE_PLANE,
@@ -85,7 +85,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     Name(const std::string& name, const std::string& id,
          const CaptureApiType api_type);
 #endif
@@ -123,7 +123,7 @@
     }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     CaptureApiType capture_api_type() const {
       return capture_api_class_.capture_api_type();
     }
@@ -155,7 +155,7 @@
     std::string device_name_;
     std::string unique_id_;
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     // This class wraps the CaptureApiType to give it a by default value if not
     // initialized.
     class CaptureApiClass {
