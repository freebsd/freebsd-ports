--- content/browser/media/media_internals.cc.orig	2020-05-13 18:40:31 UTC
+++ content/browser/media/media_internals.cc
@@ -560,7 +560,7 @@ void MediaInternals::UpdateVideoCaptureDeviceCapabilit
     device_dict->SetString("id", descriptor.device_id);
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", std::move(format_list));
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_ANDROID)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
