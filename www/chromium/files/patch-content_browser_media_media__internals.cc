--- content/browser/media/media_internals.cc.orig	2016-10-06 04:02:18.000000000 +0300
+++ content/browser/media/media_internals.cc	2016-10-13 06:53:50.938946000 +0300
@@ -724,7 +724,7 @@
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", format_list);
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
     video_capture_capabilities_cached_data_.Append(std::move(device_dict));
