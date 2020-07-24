--- chrome/browser/first_run/first_run_internal_posix.cc.orig	2020-04-10 00:39:11 UTC
+++ chrome/browser/first_run/first_run_internal_posix.cc
@@ -46,7 +46,7 @@ enum class ForcedShowDialogState {
 ForcedShowDialogState g_forced_show_dialog_state =
     ForcedShowDialogState::kNotForced;
 
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // Returns whether the first run dialog should be shown. This is only true for
 // certain builds, and only if the user has not already set preferences. In a
 // real, official-build first run, initializes the default metrics reporting if
@@ -100,7 +100,7 @@ void ForceFirstRunDialogShownForTesting(bool shown) {
 }
 
 void DoPostImportPlatformSpecificTasks(Profile* profile) {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (!ShouldShowFirstRunDialog())
     return;
 
