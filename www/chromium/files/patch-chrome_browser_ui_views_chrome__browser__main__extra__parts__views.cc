--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2019-06-04 18:55:18 UTC
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -33,7 +33,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -43,7 +43,7 @@
 #include "chrome/grit/generated_resources.h"
 #include "content/public/common/content_switches.h"
 #include "ui/base/l10n/l10n_util.h"
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 
 ChromeBrowserMainExtraPartsViews::ChromeBrowserMainExtraPartsViews() {}
 
@@ -89,7 +89,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
         g_browser_process->system_network_context_manager()->GetContext());
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
@@ -120,7 +120,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
   base::RunLoop().RunUntilIdle();
 
   exit(EXIT_FAILURE);
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 }
 
 void ChromeBrowserMainExtraPartsViews::PostBrowserStart() {
