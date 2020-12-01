--- chrome/browser/first_run/first_run_internal.h.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/first_run/first_run_internal.h
@@ -56,13 +56,13 @@ FirstRunState DetermineFirstRunState(bool has_sentinel
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if defined(OS_MAC) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MAC) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
 // build, etc).
 void ForceFirstRunDialogShownForTesting(bool shown);
-#endif  // defined(OS_MAC) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#endif  // defined(OS_MAC) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 }  // namespace internal
 }  // namespace first_run
