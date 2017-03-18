--- content/browser/media/media_internals.cc.orig	2017-03-09 20:04:32 UTC
+++ content/browser/media/media_internals.cc
@@ -776,7 +776,7 @@ void MediaInternals::UpdateVideoCaptureD
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", format_list);
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
     video_capture_capabilities_cached_data_.Append(std::move(device_dict));
