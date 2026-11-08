--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-08-13 16:48:13 UTC
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -1083,7 +1083,7 @@ void BnplManager::MaybeUpdateDesktopSuggestionsWithBnp
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
