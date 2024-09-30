--- chrome/browser/sync/chrome_sync_client.cc.orig	2024-09-30 07:45:04 UTC
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
 syncer::DataTypeControllerDelegate* GetSavedTabGroupControllerDelegate(
     Profile* profile) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   auto* keyed_service =
       tab_groups::SavedTabGroupServiceFactory::GetForProfile(profile);
   CHECK(keyed_service);
@@ -251,7 +251,7 @@ syncer::DataTypeControllerDelegate* GetSavedTabGroupCo
 syncer::DataTypeControllerDelegate* GetSharedTabGroupControllerDelegate(
     Profile* profile) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::SavedTabGroupKeyedService* keyed_service =
       tab_groups::SavedTabGroupServiceFactory::GetForProfile(profile);
   CHECK(keyed_service);
@@ -544,7 +544,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
     // platforms.
     bool enable_tab_group_sync = false;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     enable_tab_group_sync = true;
 #elif BUILDFLAG(IS_ANDROID)
     enable_tab_group_sync =
@@ -585,7 +585,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
 
 // Chrome prefers OS provided spell checkers where they exist. So only sync the
 // custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Dictionary sync is enabled by default.
     if (GetPrefService()->GetBoolean(spellcheck::prefs::kSpellCheckEnable)) {
       controllers.push_back(
