--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -58,8 +58,10 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
+#if !BUILDFLAG(IS_BSD)
 #include <gnu/libc-version.h>
+#endif
 
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
@@ -224,7 +226,7 @@ void RecordStartupMetrics() {
 
   // Record whether Chrome is the default browser or not.
   // Disabled on Linux due to hanging browser tests, see crbug.com/1216328.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   shell_integration::DefaultWebClientState default_state =
       shell_integration::GetDefaultBrowser();
   base::UmaHistogramEnumeration("DefaultBrowser.State", default_state,
