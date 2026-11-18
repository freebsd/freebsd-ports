--- components/ntp_tiles/enterprise/enterprise_shortcuts_pref_names.h.orig	2026-11-17 21:17:00 UTC
+++ components/ntp_tiles/enterprise/enterprise_shortcuts_pref_names.h
@@ -16,7 +16,7 @@ namespace ntp_tiles::prefs {
 
 // Prefs used to cache enterprise shortcuts.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kEnterpriseShortcutsPolicyList[] =
     "enterprise_shortcuts.policy_list";
 inline constexpr char kEnterpriseShortcutsUserList[] =
