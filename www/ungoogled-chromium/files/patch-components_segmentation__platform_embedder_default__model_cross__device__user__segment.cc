--- components/segmentation_platform/embedder/default_model/cross_device_user_segment.cc.orig	2025-12-06 13:30:52 UTC
+++ components/segmentation_platform/embedder/default_model/cross_device_user_segment.cc
@@ -122,7 +122,7 @@ void CrossDeviceUserSegment::ExecuteModelWithInput(
 // Check for current device type and subtract it from the device count
 // calculation.
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   desktop_count -= 1;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   if (ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET) {
