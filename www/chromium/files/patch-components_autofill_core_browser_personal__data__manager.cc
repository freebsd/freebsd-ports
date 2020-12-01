--- components/autofill/core/browser/personal_data_manager.cc.orig	2020-11-13 06:36:40 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -1960,7 +1960,7 @@ bool PersonalDataManager::IsServerCard(const CreditCar
 
 bool PersonalDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows and Mac.
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || \
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_APPLE)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
@@ -1984,7 +1984,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
   return !is_opted_in;
 #else
   return false;
-#endif // #if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || \
+#endif // #if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || defined(OS_BSD) || \
        //     defined(OS_APPLE)
 }
 
