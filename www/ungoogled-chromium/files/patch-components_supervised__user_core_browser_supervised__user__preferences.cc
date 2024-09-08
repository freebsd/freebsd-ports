--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2024-08-26 14:40:28 UTC
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -154,7 +154,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
   registry->RegisterBooleanPref(prefs::kChildAccountStatusKnown, false);
   registry->RegisterStringPref(prefs::kFamilyLinkUserMemberRole, std::string());
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
