--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2025-10-28 14:29:43 UTC
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -149,7 +149,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
   registry->RegisterBooleanPref(prefs::kChildAccountStatusKnown, false);
   registry->RegisterStringPref(prefs::kFamilyLinkUserMemberRole, std::string());
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
