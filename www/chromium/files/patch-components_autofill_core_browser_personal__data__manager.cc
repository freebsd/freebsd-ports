--- components/autofill/core/browser/personal_data_manager.cc.orig	2020-05-13 18:40:26 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -1907,7 +1907,7 @@ bool PersonalDataManager::IsServerCard(const CreditCar
 
 bool PersonalDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows and Mac.
-#if (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX)) || \
+#if (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)) || \
     defined(OS_CHROMEOS)
   return false;
 #else
@@ -1931,7 +1931,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
 
   // The option should only be shown if the user has not already opted-in.
   return !is_opted_in;
-#endif  // (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX)) ||
+#endif  // (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)) ||
         // defined(OS_CHROMEOS)
 }
 
