--- src/3rdparty/chromium/components/regional_capabilities/regional_capabilities_switches.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/regional_capabilities/regional_capabilities_switches.cc
@@ -6,7 +6,7 @@ namespace switches {
 
 namespace switches {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kClearPrefForUnknownCountry,
              "ClearCountryPrefForStoredUnknownCountry",
              base::FEATURE_DISABLED_BY_DEFAULT);
