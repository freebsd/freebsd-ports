--- components/autofill/core/common/autofill_payments_features.cc.orig	2020-05-13 18:40:26 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -101,7 +101,7 @@ const base::Feature kAutofillUpstreamEditableExpiratio
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
