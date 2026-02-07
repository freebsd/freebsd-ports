--- src/3rdparty/chromium/components/autofill/core/common/autofill_prefs.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_prefs.h
@@ -26,7 +26,7 @@ inline constexpr std::string_view kAutofillAblationSee
 inline constexpr std::string_view kAutofillAblationSeedPref =
     "autofill.ablation_seed";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that is true if BNPL on Autofill is enabled.
 inline constexpr char kAutofillBnplEnabled[] = "autofill.bnpl_enabled";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -80,7 +80,7 @@ inline constexpr char kAutofillPaymentCardBenefits[] =
 inline constexpr char kAutofillPaymentCardBenefits[] =
     "autofill.payment_card_benefits";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that controls improved autofill filling predictions. When enabled,
 // the autofill functionality is enhanced with adopting user data to
 // the form being filled in, which is triggered by the user via an extra
@@ -235,7 +235,7 @@ bool IsFacilitatedPaymentsEwalletEnabled(const PrefSer
 bool IsFacilitatedPaymentsEwalletEnabled(const PrefService* prefs);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
