--- services/device/public/cpp/device_features.h.orig	2026-09-25 15:26:43 UTC
+++ services/device/public/cpp/device_features.h
@@ -68,11 +68,11 @@ DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermis
 DEVICE_FEATURES_EXPORT device::mojom::LocationProviderManagerMode
 GetLocationProviderManagerMode();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kProductNameOverHidName);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
