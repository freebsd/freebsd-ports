--- content/browser/media/media_internals.cc.orig	2019-03-11 22:00:57 UTC
+++ content/browser/media/media_internals.cc
@@ -763,7 +763,7 @@ void MediaInternals::UpdateVideoCaptureDeviceCapabilit
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", std::move(format_list));
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
     video_capture_capabilities_cached_data_.Append(std::move(device_dict));
