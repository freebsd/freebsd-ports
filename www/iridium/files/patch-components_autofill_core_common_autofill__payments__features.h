--- components/autofill/core/common/autofill_payments_features.h.orig	2024-08-27 06:28:16 UTC
+++ components/autofill/core/common/autofill_payments_features.h
@@ -14,7 +14,7 @@ namespace autofill::features {
 
 // All features in alphabetical order.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillEnableAmountExtractionDesktop);
 #endif
