--- components/autofill/core/common/autofill_payments_features.cc.orig	2022-02-28 16:54:41 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -180,7 +180,7 @@ const base::Feature kAutofillUpstreamAllowAllEmailDoma
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
