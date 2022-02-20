--- chrome/browser/profiles/profiles_state.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/profiles/profiles_state.cc
@@ -176,7 +176,7 @@ bool IsGuestModeRequested(const base::CommandLine& com
                           PrefService* local_state,
                           bool show_warning) {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   DCHECK(local_state);
 
   // Check if guest mode enforcement commandline switch or policy are provided.
