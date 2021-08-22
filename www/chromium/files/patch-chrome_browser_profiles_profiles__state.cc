--- chrome/browser/profiles/profiles_state.cc.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/profiles/profiles_state.cc
@@ -185,7 +185,7 @@ bool IsRegularOrGuestSession(Browser* browser) {
 bool IsGuestModeRequested(const base::CommandLine& command_line,
                           PrefService* local_state,
                           bool show_warning) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
   DCHECK(local_state);
 
