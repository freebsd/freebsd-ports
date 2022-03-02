--- chrome/browser/first_run/first_run_internal.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/first_run/first_run_internal.h
@@ -58,7 +58,7 @@ FirstRunState DetermineFirstRunState(bool has_sentinel
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
