--- services/device/public/cpp/device_features.cc.orig	2026-04-16 10:10:12 UTC
+++ services/device/public/cpp/device_features.cc
@@ -135,11 +135,11 @@ bool IsOsLevelGeolocationPermissionSupportEnabled() {
 // a USB interface is busy.
 #if BUILDFLAG(IS_ANDROID)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Controls whether we report the product name (like macOS and Win)
 // over the HID_NAME in the WebHID API.
 BASE_FEATURE(kProductNameOverHidName, base::FEATURE_ENABLED_BY_DEFAULT);
