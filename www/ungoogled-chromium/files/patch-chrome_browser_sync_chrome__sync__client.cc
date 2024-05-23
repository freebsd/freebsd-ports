--- chrome/browser/sync/chrome_sync_client.cc.orig	2024-05-23 20:04:36 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -108,7 +108,7 @@
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_keyed_service.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #elif BUILDFLAG(IS_ANDROID)
@@ -463,7 +463,7 @@ ChromeSyncClient::CreateModelTypeControllers(
     // platforms.
     bool enable_tab_group_sync = false;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     enable_tab_group_sync = true;
 #elif BUILDFLAG(IS_ANDROID)
     enable_tab_group_sync =
@@ -481,7 +481,7 @@ ChromeSyncClient::CreateModelTypeControllers(
 
 // Chrome prefers OS provided spell checkers where they exist. So only sync the
 // custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Dictionary sync is enabled by default.
     if (GetPrefService()->GetBoolean(spellcheck::prefs::kSpellCheckEnable)) {
       controllers.push_back(
@@ -638,7 +638,7 @@ ChromeSyncClient::GetControllerDelegateForModelType(sy
   switch (type) {
     case syncer::SAVED_TAB_GROUP: {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       auto* keyed_service =
           tab_groups::SavedTabGroupServiceFactory::GetForProfile(profile_);
       CHECK(keyed_service);
