--- components/autofill/core/browser/personal_data_manager.cc.orig	2023-01-13 08:56:02 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -2079,7 +2079,8 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
   if (!sync_service_ || sync_service_->IsSyncFeatureEnabled() ||
