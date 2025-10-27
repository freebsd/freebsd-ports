--- components/ntp_tiles/pref_names.h.orig	2025-10-21 16:57:35 UTC
+++ components/ntp_tiles/pref_names.h
@@ -48,7 +48,7 @@ inline constexpr char kCustomLinksInitialized[] = "cus
 
 // Prefs used to cache enterprise shortcuts.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kEnterpriseShortcutsPolicyList[] =
     "enterprise_shortcuts.policy_list";
 inline constexpr char kEnterpriseShortcutsUserList[] =
