--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -274,7 +274,7 @@ bool CanOpenProfileOnStartup(Profile* profile) {
 // true, send a warning if guest mode is requested but not allowed by policy.
 bool IsGuestModeEnforced(const base::CommandLine& command_line,
                          bool show_warning) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
   PrefService* service = g_browser_process->local_state();
   DCHECK(service);
