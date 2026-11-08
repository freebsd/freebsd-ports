--- src/3rdparty/chromium/services/device/public/cpp/device_features.h.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/services/device/public/cpp/device_features.h
@@ -62,7 +62,7 @@ DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermis
 
 DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermissionSupportEnabled();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
