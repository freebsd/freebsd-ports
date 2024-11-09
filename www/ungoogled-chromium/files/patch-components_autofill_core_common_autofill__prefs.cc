--- components/autofill/core/common/autofill_prefs.cc.orig	2024-10-27 06:40:35 UTC
+++ components/autofill/core/common/autofill_prefs.cc
@@ -118,7 +118,7 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAutofillPredictionImprovementsEnabled,
                                 false);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
