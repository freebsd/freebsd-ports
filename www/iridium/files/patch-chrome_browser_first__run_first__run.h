--- chrome/browser/first_run/first_run.h.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/first_run/first_run.h
@@ -74,7 +74,7 @@ struct MasterPrefs {
 #if BUILDFLAG(IS_MAC)
   bool confirm_to_quit;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   bool eula_required = true;
 #else
@@ -150,7 +150,7 @@ ProcessInitialPreferencesResult ProcessInitialPreferen
     std::unique_ptr<installer::InitialPreferences> initial_prefs,
     MasterPrefs* out_prefs);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Shows the EULA dialog if required. Returns true if the EULA is accepted
 // or not required. Returns false if the EULA has not been accepted. If the EULA
 // has not been accepted, the caller should exit promptly.
