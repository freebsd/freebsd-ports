--- content/shell/browser/shell_browser_main_parts.cc.orig	2016-05-11 19:02:22 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -40,7 +40,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
 #include "ui/base/ime/input_method_initializer.h"
 #endif
 #if defined(OS_CHROMEOS)
@@ -124,7 +124,7 @@ void ShellBrowserMainParts::PostMainMess
 }
 
 void ShellBrowserMainParts::PreEarlyInitialization() {
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
