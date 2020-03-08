--- components/autofill/core/common/autofill_payments_features.cc.orig	2020-03-03 18:53:53 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -130,7 +130,7 @@ const base::Feature kAutofillUpstreamEditableExpiratio
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #endif
