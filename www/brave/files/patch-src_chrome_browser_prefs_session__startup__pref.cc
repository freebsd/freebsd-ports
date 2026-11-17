--- src/chrome/browser/prefs/session_startup_pref.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/prefs/session_startup_pref.cc
@@ -66,7 +66,7 @@ SessionStartupPref::Type SessionStartupP
 #if BUILDFLAG(IS_CHROMEOS)
   return SessionStartupPref::LAST;
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }
