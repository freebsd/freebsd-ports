--- src/3rdparty/chromium/components/permissions/prediction_service/prediction_common.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/permissions/prediction_service/prediction_common.cc
@@ -32,7 +32,7 @@ ClientFeatures_Platform GetCurrentPlatformProto() {
 
 ClientFeatures_Platform GetCurrentPlatformProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_Platform_PLATFORM_DESKTOP;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_Platform_PLATFORM_MOBILE;
@@ -43,7 +43,7 @@ ClientFeatures_PlatformEnum GetCurrentPlatformEnumProt
 
 ClientFeatures_PlatformEnum GetCurrentPlatformEnumProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_DESKTOP_V2;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_MOBILE_V2;
