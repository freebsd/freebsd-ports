--- components/autofill/core/common/autofill_prefs.cc.orig	2026-01-14 08:33:23 UTC
+++ components/autofill/core/common/autofill_prefs.cc
@@ -140,7 +140,7 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       kAutofillBnplEnabled, true,
       user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
@@ -436,7 +436,7 @@ void SetFacilitatedPaymentsA2ATriggeredOnce(PrefServic
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value) {
   prefs->SetBoolean(kAutofillBnplEnabled, value);
 }
@@ -445,7 +445,7 @@ void SetAutofillBnplEnabled(PrefService* prefs, bool v
 
 bool IsAutofillBnplEnabled(const PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return prefs->GetBoolean(kAutofillBnplEnabled);
 #else
   return false;
@@ -454,7 +454,7 @@ bool IsAutofillBnplEnabled(const PrefService* prefs) {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // If called, always sets the pref to true, and once true, it will follow the
 // user around forever.
 void SetAutofillHasSeenBnpl(PrefService* prefs) {
