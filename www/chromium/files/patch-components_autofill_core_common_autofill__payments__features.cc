--- components/autofill/core/common/autofill_payments_features.cc.orig	2020-11-13 06:36:40 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -123,7 +123,7 @@ const base::Feature kAutofillUpstreamAllowAllEmailDoma
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 #if defined(OS_WIN) || defined(OS_APPLE) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
