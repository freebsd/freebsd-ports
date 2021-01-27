--- components/autofill/core/browser/personal_data_manager.cc.orig	2021-01-18 21:28:54 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -1957,7 +1957,7 @@ bool PersonalDataManager::IsServerCard(const CreditCar
 
 bool PersonalDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows and Mac.
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || \
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_APPLE)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
@@ -1981,7 +1981,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
   return !is_opted_in;
 #else
   return false;
-#endif  // #if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || \
+#endif  // #if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || defined(OS_BSD) || \
        //     defined(OS_APPLE)
 }
 
