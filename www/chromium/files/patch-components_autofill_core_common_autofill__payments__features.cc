--- components/autofill/core/common/autofill_payments_features.cc.orig	2021-04-14 18:40:58 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -122,7 +122,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_APPLE) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
