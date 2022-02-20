--- components/autofill/core/common/autofill_payments_features.cc.orig	2022-02-07 13:39:41 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -172,7 +172,7 @@ const base::Feature kAutofillUpstreamAllowAllEmailDoma
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_APPLE) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
