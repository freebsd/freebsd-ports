--- chrome/browser/sync/sync_service_factory.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/sync/sync_service_factory.cc
@@ -140,7 +140,7 @@ namespace {
 tab_groups::TabGroupSyncService* GetTabGroupSyncService(Profile* profile) {
   CHECK(profile);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::TabGroupSyncService* service =
       tab_groups::TabGroupSyncServiceFactory::GetForProfile(profile);
   CHECK(service);
