--- components/autofill/core/browser/autofill_experiments.cc.orig	2019-12-16 21:50:45 UTC
+++ components/autofill/core/browser/autofill_experiments.cc
@@ -233,7 +233,7 @@ bool IsAutofillNoLocalSaveOnUploadSuccessExperimentEna
 }
 
 bool OfferStoreUnmaskedCards(bool is_off_the_record) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The checkbox can be forced on with a flag, but by default we don't store
   // on Linux due to lack of system keychain integration. See crbug.com/162735
   return base::CommandLine::ForCurrentProcess()->HasSwitch(
