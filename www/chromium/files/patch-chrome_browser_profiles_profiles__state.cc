--- chrome/browser/profiles/profiles_state.cc.orig	2021-03-12 23:57:18 UTC
+++ chrome/browser/profiles/profiles_state.cc
@@ -180,7 +180,7 @@ bool IsRegularOrGuestSession(Browser* browser) {
 bool IsGuestModeRequested(const base::CommandLine& command_line,
                           PrefService* local_state,
                           bool show_warning) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
   DCHECK(local_state);
 
