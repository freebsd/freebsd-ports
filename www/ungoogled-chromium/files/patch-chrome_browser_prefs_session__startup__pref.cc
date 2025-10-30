--- chrome/browser/prefs/session_startup_pref.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/prefs/session_startup_pref.cc
@@ -71,7 +71,7 @@ SessionStartupPref::Type SessionStartupPref::GetDefaul
 #if BUILDFLAG(IS_CHROMEOS)
   return SessionStartupPref::LAST;
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }
