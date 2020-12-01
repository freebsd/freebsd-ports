--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -34,7 +34,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -44,7 +44,7 @@
 #include "chrome/grit/generated_resources.h"
 #include "content/public/common/content_switches.h"
 #include "ui/base/l10n/l10n_util.h"
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 
 // This connector is used in ui_devtools's TracingAgent to hook up with the
 // tracing service.
@@ -114,7 +114,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
         return controller;
       }));
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
@@ -145,7 +145,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
   base::RunLoop().RunUntilIdle();
 
   exit(EXIT_FAILURE);
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 }
 
 void ChromeBrowserMainExtraPartsViews::PostBrowserStart() {
