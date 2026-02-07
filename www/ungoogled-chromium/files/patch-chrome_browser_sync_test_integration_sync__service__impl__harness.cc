--- chrome/browser/sync/test/integration/sync_service_impl_harness.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/sync/test/integration/sync_service_impl_harness.cc
@@ -486,7 +486,7 @@ bool SyncServiceImplHarness::EnableHistorySyncNoWaitFo
   // Tabs and history are bundled together in the same toggle.
   service()->GetUserSettings()->SetSelectedType(
       syncer::UserSelectableType::kTabs, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop platforms, kSavedTabGroups are not merged to kTabs yet, but
   // they're enabled together.
   service()->GetUserSettings()->SetSelectedType(
