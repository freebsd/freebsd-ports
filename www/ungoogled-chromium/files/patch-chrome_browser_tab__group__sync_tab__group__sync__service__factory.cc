--- chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc.orig	2024-08-26 14:40:28 UTC
+++ chrome/browser/tab_group_sync/tab_group_sync_service_factory.cc
@@ -110,7 +110,7 @@ TabGroupSyncServiceFactory::BuildServiceInstanceForBro
 
   std::unique_ptr<TabGroupSyncDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   delegate =
       std::make_unique<TabGroupSyncDelegateDesktop>(service.get(), profile);
 #else
