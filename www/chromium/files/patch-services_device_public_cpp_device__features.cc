--- services/device/public/cpp/device_features.cc.orig	2025-05-05 10:57:53 UTC
+++ services/device/public/cpp/device_features.cc
@@ -135,7 +135,7 @@ bool IsOsLevelGeolocationPermissionSupportEnabled() {
 
 // Controls whether Chrome will try to automatically detach kernel drivers when
 // a USB interface is busy.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_DISABLED_BY_DEFAULT);
