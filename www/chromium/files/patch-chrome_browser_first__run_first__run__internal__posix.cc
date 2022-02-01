--- chrome/browser/first_run/first_run_internal_posix.cc.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/first_run/first_run_internal_posix.cc
@@ -36,7 +36,7 @@ enum class ForcedShowDialogState {
 ForcedShowDialogState g_forced_show_dialog_state =
     ForcedShowDialogState::kNotForced;
 
-#if !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
 // Returns whether the first run dialog should be shown. This is only true for
 // certain builds, and only if the user has not already set preferences. In a
 // real, official-build first run, initializes the default metrics reporting if
@@ -81,7 +81,7 @@ void ForceFirstRunDialogShownForTesting(bool shown) {
 }
 
 void DoPostImportPlatformSpecificTasks(Profile* profile) {
-#if !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
   if (!ShouldShowFirstRunDialog())
     return;
 
