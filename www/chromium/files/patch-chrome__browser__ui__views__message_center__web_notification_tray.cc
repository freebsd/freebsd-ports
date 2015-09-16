--- chrome/browser/ui/views/message_center/web_notification_tray.cc.orig	2015-04-28 09:44:00.558139000 -0400
+++ chrome/browser/ui/views/message_center/web_notification_tray.cc	2015-04-28 09:44:33.539806000 -0400
@@ -31,7 +31,7 @@
 #include "ui/strings/grit/ui_strings.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -66,7 +66,7 @@
 }
 
 bool CanDestroyStatusIcon() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Avoid creating multiple system tray icons on KDE4 and newer versions of KDE
   // because the OS does not support removing system tray icons.
   // TODO(pkotwicz): This is a hack for the sake of M40. Fix this properly.
