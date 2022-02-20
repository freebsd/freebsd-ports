--- components/autofill/core/browser/personal_data_manager.cc.orig	2022-02-07 13:39:41 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -2097,7 +2097,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_WIN) || \
-    defined(OS_APPLE) || defined(OS_FUCHSIA)
+    defined(OS_APPLE) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
   if (!sync_service_ || sync_service_->IsSyncFeatureEnabled() ||
