--- components/autofill/core/browser/personal_data_manager.cc.orig	2020-09-08 19:14:03 UTC
+++ components/autofill/core/browser/personal_data_manager.cc
@@ -1916,7 +1916,7 @@ bool PersonalDataManager::IsServerCard(const CreditCar
 
 bool PersonalDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows and Mac.
-#if (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX)) || \
+#if (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)) || \
     defined(OS_CHROMEOS)
   return false;
 #else
@@ -1940,7 +1940,7 @@ bool PersonalDataManager::ShouldShowCardsFromAccountOp
 
   // The option should only be shown if the user has not already opted-in.
   return !is_opted_in;
-#endif  // (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX)) ||
+#endif  // (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)) ||
         // defined(OS_CHROMEOS)
 }
 
