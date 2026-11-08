--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-09-25 15:26:43 UTC
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -1177,7 +1177,7 @@ void BnplManager::MaybeUpdateDesktopSuggestionsWithBnp
           /*pay_later_tab_shown=*/false);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
