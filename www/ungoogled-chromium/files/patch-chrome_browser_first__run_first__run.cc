--- chrome/browser/first_run/first_run.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/first_run/first_run.cc
@@ -309,7 +309,7 @@ void SetupInitialPrefsFromInstallPrefs(
     out_prefs->confirm_to_quit = true;
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   install_prefs.GetBool(installer::initial_preferences::kRequireEula,
                         &out_prefs->eula_required);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -458,7 +458,7 @@ ProcessInitialPreferencesResult ProcessInitialPreferen
   return FIRST_RUN_PROCEED;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ShowEulaDialog() {
   return internal::ShowEulaDialog();
 }
