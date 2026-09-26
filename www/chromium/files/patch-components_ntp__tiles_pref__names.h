--- components/ntp_tiles/pref_names.h.orig	2026-09-25 15:26:43 UTC
+++ components/ntp_tiles/pref_names.h
@@ -57,7 +57,7 @@ inline constexpr char kCustomLinksInitialized[] = "cus
 
 // Prefs used to cache enterprise shortcuts.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kEnterpriseShortcutsPolicyList[] =
     "enterprise_shortcuts.policy_list";
 inline constexpr char kEnterpriseShortcutsUserList[] =
