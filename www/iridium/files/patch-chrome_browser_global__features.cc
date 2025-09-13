--- chrome/browser/global_features.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/global_features.cc
@@ -24,7 +24,7 @@
 #include "chrome/browser/glic/host/glic_synthetic_trial_manager.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This causes a gn error on Android builds, because gn does not understand
 // buildflags, so we include it only on platforms where it is used.
 #include "chrome/browser/ui/webui/whats_new/whats_new_registrar.h"
@@ -70,7 +70,7 @@ void GlobalFeatures::ReplaceGlobalFeaturesForTesting(
 
 void GlobalFeatures::Init() {
   system_permissions_platform_handle_ = CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   whats_new_registry_ = CreateWhatsNewRegistry();
 #endif
 
@@ -119,7 +119,7 @@ GlobalFeatures::CreateSystemPermissionsPlatformHandle(
   return system_permission_settings::PlatformHandle::Create();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
