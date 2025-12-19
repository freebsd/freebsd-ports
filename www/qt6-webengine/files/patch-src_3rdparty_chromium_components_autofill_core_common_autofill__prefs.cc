--- src/3rdparty/chromium/components/autofill/core/common/autofill_prefs.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_prefs.cc
@@ -102,7 +102,7 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAutofillPredictionImprovementsEnabled,
                                 false);
   registry->RegisterBooleanPref(
@@ -294,7 +294,7 @@ bool IsFacilitatedPaymentsEwalletEnabled(const PrefSer
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value) {
   prefs->SetBoolean(kAutofillBnplEnabled, value);
 }
@@ -303,7 +303,7 @@ bool IsAutofillBnplEnabled(const PrefService* prefs) {
 
 bool IsAutofillBnplEnabled(const PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return prefs->GetBoolean(kAutofillBnplEnabled);
 #else
   return false;
