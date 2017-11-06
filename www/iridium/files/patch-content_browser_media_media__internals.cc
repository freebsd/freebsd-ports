--- content/browser/media/media_internals.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/media/media_internals.cc
@@ -774,7 +774,7 @@ void MediaInternals::UpdateVideoCaptureD
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", format_list);
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
     video_capture_capabilities_cached_data_.Append(std::move(device_dict));
