--- components/autofill/core/browser/personal_data_manager.cc.orig	2022-02-28 16:54:41 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -2107,7 +2107,8 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
   if (!sync_service_ || sync_service_->IsSyncFeatureEnabled() ||
