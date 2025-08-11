--- components/autofill/core/common/autofill_prefs.cc.orig	2025-08-07 06:57:29 UTC
+++ components/autofill/core/common/autofill_prefs.cc
@@ -104,7 +104,7 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       kAutofillBnplEnabled, true,
       user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
@@ -298,7 +298,7 @@ bool IsFacilitatedPaymentsPixAccountLinkingEnabled(con
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value) {
   prefs->SetBoolean(kAutofillBnplEnabled, value);
 }
@@ -307,7 +307,7 @@ void SetAutofillBnplEnabled(PrefService* prefs, bool v
 
 bool IsAutofillBnplEnabled(const PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return prefs->GetBoolean(kAutofillBnplEnabled);
 #else
   return false;
@@ -316,7 +316,7 @@ bool IsAutofillBnplEnabled(const PrefService* prefs) {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // If called, always sets the pref to true, and once true, it will follow the
 // user around forever.
 void SetAutofillHasSeenBnpl(PrefService* prefs) {
