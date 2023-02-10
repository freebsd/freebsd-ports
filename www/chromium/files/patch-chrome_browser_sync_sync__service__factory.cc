--- chrome/browser/sync/sync_service_factory.cc.orig	2023-02-08 09:03:45 UTC
+++ chrome/browser/sync/sync_service_factory.cc
@@ -74,7 +74,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_service_factory.h"
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_WIN)
@@ -115,7 +115,7 @@ std::unique_ptr<KeyedService> BuildSyncService(
 // TODO(crbug.com/1052397): Reassess whether the following block needs to be
 // included in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
@@ -251,7 +251,7 @@ SyncServiceFactory::SyncServiceFactory()
   DependsOn(ThemeServiceFactory::GetInstance());
 #endif  // !BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   DependsOn(SavedTabGroupServiceFactory::GetInstance());
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_WIN)
