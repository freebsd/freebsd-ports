--- components/autofill/core/common/autofill_prefs.h.orig	2024-10-27 06:40:35 UTC
+++ components/autofill/core/common/autofill_prefs.h
@@ -73,7 +73,7 @@ inline constexpr char kAutofillPaymentCvcStorage[] =
 inline constexpr char kAutofillPaymentCardBenefits[] =
     "autofill.payment_card_benefits";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that controls improved autofill filling predictions. When enabled,
 // the autofill functionality is enhanced with adopting user data to
 // the form being filled in, which is triggered by the user via an extra
