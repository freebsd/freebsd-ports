--- src/3rdparty/chromium/content/browser/media/media_internals.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/media/media_internals.cc
@@ -755,7 +755,7 @@ void MediaInternals::UpdateVideoCaptureD
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", format_list);
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
     video_capture_capabilities_cached_data_.Append(std::move(device_dict));
