--- media/capture/video/video_capture_device.h.orig	2015-10-14 18:04:30.325845000 +0200
+++ media/capture/video/video_capture_device.h	2015-10-14 18:06:41.271627000 +0200
@@ -43,7 +43,7 @@
     Name();
     Name(const std::string& name, const std::string& id);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Linux/CrOS targets Capture Api type: it can only be set on construction.
     enum CaptureApiType {
       V4L2_SINGLE_PLANE,
@@ -75,7 +75,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     Name(const std::string& name,
          const std::string& id,
          const CaptureApiType api_type);
@@ -112,7 +112,7 @@
     bool operator<(const Name& other) const { return unique_id_ < other.id(); }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     CaptureApiType capture_api_type() const {
       return capture_api_class_.capture_api_type();
     }
@@ -136,7 +136,7 @@
     std::string device_name_;
     std::string unique_id_;
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     // This class wraps the CaptureApiType to give it a by default value if not
     // initialized.
     class CaptureApiClass {
