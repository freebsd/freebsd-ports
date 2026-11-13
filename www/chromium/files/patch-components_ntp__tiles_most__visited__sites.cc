--- components/ntp_tiles/most_visited_sites.cc.orig	2026-11-11 14:44:17 UTC
+++ components/ntp_tiles/most_visited_sites.cc
@@ -51,7 +51,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/ntp_tiles/enterprise/enterprise_shortcuts_pref_names.h"
 #include "components/ntp_tiles/enterprise/enterprise_shortcuts_store.h"
 #endif
@@ -1007,7 +1007,7 @@ bool MostVisitedSites::IsNtpTileFromPreinstalledApp(GU
 // static
 bool MostVisitedSites::HasEnterpriseShortcuts(const PrefService& prefs) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return EnterpriseShortcutsStore::HasPolicyLinks(prefs);
 #else
   return false;
@@ -1019,7 +1019,7 @@ void MostVisitedSites::AddEnterpriseShortcutsObserver(
     PrefChangeRegistrar& registrar,
     const base::RepeatingClosure& callback) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registrar.Add(prefs::kEnterpriseShortcutsPolicyList, callback);
 #endif
 }
