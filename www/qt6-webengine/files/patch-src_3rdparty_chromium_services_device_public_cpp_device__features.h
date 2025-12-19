--- src/3rdparty/chromium/services/device/public/cpp/device_features.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/services/device/public/cpp/device_features.h
@@ -51,7 +51,7 @@ DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermis
 
 DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermissionSupportEnabled();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
