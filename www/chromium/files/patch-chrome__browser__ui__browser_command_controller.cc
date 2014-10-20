--- chrome/browser/ui/browser_command_controller.cc.orig	2014-10-14 21:32:48.000000000 +0200
+++ chrome/browser/ui/browser_command_controller.cc	2014-10-14 21:22:15.000000000 +0200
@@ -67,7 +67,7 @@
 #include "chrome/browser/ui/browser_commands_chromeos.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
 
@@ -279,7 +279,7 @@
   if (window()->IsFullscreen() && command_id == IDC_FULLSCREEN)
     return true;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
