--- components/autofill/core/common/autofill_payments_features.cc.orig	2020-09-08 19:14:03 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -124,7 +124,7 @@ const base::Feature kAutofillUpstreamAllowAllEmailDoma
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
