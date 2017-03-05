--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2017-02-02 02:02:50 UTC
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -24,14 +24,14 @@
 #include "ui/wm/core/wm_state.h"
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "base/command_line.h"
 #include "chrome/browser/ui/simple_message_box.h"
 #include "chrome/grit/chromium_strings.h"
 #include "chrome/grit/generated_resources.h"
 #include "content/public/common/content_switches.h"
 #include "ui/base/l10n/l10n_util.h"
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 
 ChromeBrowserMainExtraPartsViews::ChromeBrowserMainExtraPartsViews() {
 }
@@ -62,7 +62,7 @@ void ChromeBrowserMainExtraPartsViews::P
 }
 
 void ChromeBrowserMainExtraPartsViews::PreProfileInit() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
