--- chrome/browser/first_run/first_run_internal.h.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/first_run/first_run_internal.h
@@ -72,13 +72,13 @@ FirstRunState DetermineFirstRunState(bool has_sentinel
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Shows the EULA dialog if required. Returns true if the EULA is accepted
 // or not required. Returns false if the EULA has not been accepted.
 bool ShowEulaDialog();
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
