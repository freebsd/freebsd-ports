--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2025-01-25 09:34:31 UTC
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -147,7 +147,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
       prefs::kFamilyLinkUserState,
       static_cast<int>(FamilyLinkUserState::kUnknown));
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
