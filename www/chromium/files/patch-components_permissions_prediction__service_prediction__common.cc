--- components/permissions/prediction_service/prediction_common.cc.orig	2025-07-02 06:08:04 UTC
+++ components/permissions/prediction_service/prediction_common.cc
@@ -36,7 +36,7 @@ int BucketizeValue(int count) {
 
 ClientFeatures_Platform GetCurrentPlatformProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_Platform_PLATFORM_DESKTOP;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_Platform_PLATFORM_MOBILE;
@@ -47,7 +47,7 @@ ClientFeatures_Platform GetCurrentPlatformProto() {
 
 ClientFeatures_PlatformEnum GetCurrentPlatformEnumProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_DESKTOP_V2;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_MOBILE_V2;
