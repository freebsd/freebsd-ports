--- chrome/browser/sync/sync_service_factory.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/sync/sync_service_factory.cc
@@ -84,7 +84,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "chrome/browser/tab_group_sync/tab_group_sync_service_factory.h"
@@ -135,7 +135,7 @@ std::unique_ptr<KeyedService> BuildSyncService(
 // TODO(crbug.com/40118868): Reassess whether the following block needs to be
 // included in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
@@ -274,7 +274,7 @@ SyncServiceFactory::SyncServiceFactory()
   DependsOn(ProfilePasswordStoreFactory::GetInstance());
   DependsOn(PowerBookmarkServiceFactory::GetInstance());
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   DependsOn(tab_groups::SavedTabGroupServiceFactory::GetInstance());
 #elif BUILDFLAG(IS_ANDROID)
   DependsOn(tab_groups::TabGroupSyncServiceFactory::GetInstance());
