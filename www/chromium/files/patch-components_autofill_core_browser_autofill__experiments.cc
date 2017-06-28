--- components/autofill/core/browser/autofill_experiments.cc.orig	2017-06-05 19:03:05 UTC
+++ components/autofill/core/browser/autofill_experiments.cc
@@ -153,7 +153,7 @@ unsigned int GetPopupMargin() {
 }
 
 bool OfferStoreUnmaskedCards() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // The checkbox can be forced on with a flag, but by default we don't store
   // on Linux due to lack of system keychain integration. See crbug.com/162735
   return base::CommandLine::ForCurrentProcess()->HasSwitch(
