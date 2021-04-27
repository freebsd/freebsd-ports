--- components/autofill/core/browser/personal_data_manager.cc.orig	2021-04-14 18:40:58 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -1931,7 +1931,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
 // The feature is only for Linux, Windows and Mac.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN) || \
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_APPLE)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
@@ -1955,7 +1955,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
   return !is_opted_in;
 #else
   return false;
-#endif  // #if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) ||
+#endif  // #if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) ||
         // defined(OS_WIN) || defined(OS_APPLE)
 }
 
