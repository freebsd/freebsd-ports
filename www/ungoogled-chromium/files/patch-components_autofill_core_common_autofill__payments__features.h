--- components/autofill/core/common/autofill_payments_features.h.orig	2025-01-25 09:34:31 UTC
+++ components/autofill/core/common/autofill_payments_features.h
@@ -17,7 +17,7 @@ COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillDisableLocalCardMigration);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillEnableAmountExtractionDesktop);
 #endif
