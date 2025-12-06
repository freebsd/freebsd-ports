--- components/autofill/core/common/autofill_prefs.h.orig	2025-12-05 10:12:50 UTC
+++ components/autofill/core/common/autofill_prefs.h
@@ -44,7 +44,7 @@ inline constexpr char kAutofillAiLastVersionDeduped[] 
 inline constexpr char kAutofillAiTravelEntitiesEnabled[] =
     "autofill.autofill_ai.travel_entities_enabled";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Boolean that is true if BNPL on Autofill is enabled.
 inline constexpr char kAutofillBnplEnabled[] = "autofill.bnpl_enabled";
 // Boolean that is true if the user has ever seen a BNPL suggestion.
@@ -277,7 +277,7 @@ bool IsFacilitatedPaymentsA2AEnabled(const PrefService
 void SetFacilitatedPaymentsA2ATriggeredOnce(PrefService* prefs, bool value);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
@@ -285,7 +285,7 @@ void SetAutofillBnplEnabled(PrefService* prefs, bool v
 bool IsAutofillBnplEnabled(const PrefService* prefs);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void SetAutofillHasSeenBnpl(PrefService* prefs);
 
 bool HasSeenBnpl(const PrefService* prefs);
