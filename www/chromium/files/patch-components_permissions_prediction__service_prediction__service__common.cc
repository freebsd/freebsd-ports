--- components/permissions/prediction_service/prediction_service_common.cc.orig	2021-04-14 18:41:00 UTC
+++ components/permissions/prediction_service/prediction_service_common.cc
@@ -12,7 +12,7 @@
 
 namespace permissions {
 ClientFeatures_Platform GetCurrentPlatformProto() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   return permissions::ClientFeatures_Platform_PLATFORM_DESKTOP;
 #elif defined(OS_ANDROID) || defined(OS_FUCHSIA)
