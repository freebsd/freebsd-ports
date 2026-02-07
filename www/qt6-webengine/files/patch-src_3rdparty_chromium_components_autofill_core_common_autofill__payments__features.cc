--- src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc
@@ -304,7 +304,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
