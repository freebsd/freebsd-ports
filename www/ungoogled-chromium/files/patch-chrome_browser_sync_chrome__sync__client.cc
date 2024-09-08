--- chrome/browser/sync/chrome_sync_client.cc.orig	2024-08-26 14:40:28 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -119,7 +119,7 @@
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_keyed_service.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #elif BUILDFLAG(IS_ANDROID)
@@ -233,7 +233,7 @@ bool ShouldSyncAppsTypesInTransportMode() {
 syncer::ModelTypeControllerDelegate* GetSavedTabGroupControllerDelegate(
     Profile* profile) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   auto* keyed_service =
       tab_groups::SavedTabGroupServiceFactory::GetForProfile(profile);
   CHECK(keyed_service);
@@ -251,7 +251,7 @@ syncer::ModelTypeControllerDelegate* GetSavedTabGroupC
 syncer::ModelTypeControllerDelegate* GetSharedTabGroupControllerDelegate(
     Profile* profile) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::SavedTabGroupKeyedService* keyed_service =
       tab_groups::SavedTabGroupServiceFactory::GetForProfile(profile);
   CHECK(keyed_service);
@@ -545,7 +545,7 @@ ChromeSyncClient::CreateModelTypeControllers(
     // platforms.
     bool enable_tab_group_sync = false;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     enable_tab_group_sync = true;
 #elif BUILDFLAG(IS_ANDROID)
     enable_tab_group_sync =
@@ -586,7 +586,7 @@ ChromeSyncClient::CreateModelTypeControllers(
 
 // Chrome prefers OS provided spell checkers where they exist. So only sync the
 // custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Dictionary sync is enabled by default.
     if (GetPrefService()->GetBoolean(spellcheck::prefs::kSpellCheckEnable)) {
       controllers.push_back(
