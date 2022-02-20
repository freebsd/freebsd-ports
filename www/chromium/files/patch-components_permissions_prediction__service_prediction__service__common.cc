--- components/permissions/prediction_service/prediction_service_common.cc.orig	2022-02-07 13:39:41 UTC
+++ components/permissions/prediction_service/prediction_service_common.cc
@@ -13,7 +13,7 @@
 namespace permissions {
 ClientFeatures_Platform GetCurrentPlatformProto() {
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   return permissions::ClientFeatures_Platform_PLATFORM_DESKTOP;
 #elif defined(OS_ANDROID) || defined(OS_FUCHSIA)
   return permissions::ClientFeatures_Platform_PLATFORM_MOBILE;
