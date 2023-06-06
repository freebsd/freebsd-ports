--- components/autofill/core/common/autofill_payments_features.cc.orig	2023-06-05 19:39:05 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -274,7 +274,7 @@ const base::FeatureParam<int>
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
