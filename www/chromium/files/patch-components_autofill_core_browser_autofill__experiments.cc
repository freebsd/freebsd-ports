--- components/autofill/core/browser/autofill_experiments.cc.orig	2017-04-19 19:06:32 UTC
+++ components/autofill/core/browser/autofill_experiments.cc
@@ -151,7 +151,7 @@ unsigned int GetPopupMargin() {
 }
 
 bool OfferStoreUnmaskedCards() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // The checkbox can be forced on with a flag, but by default we don't store
   // on Linux due to lack of system keychain integration. See crbug.com/162735
   return base::CommandLine::ForCurrentProcess()->HasSwitch(
