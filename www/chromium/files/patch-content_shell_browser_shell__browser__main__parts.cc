--- content/shell/browser/shell_browser_main_parts.cc.orig	2017-01-26 00:49:13 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -44,7 +44,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
 #include "ui/base/ime/input_method_initializer.h"
 #endif
 #if defined(OS_CHROMEOS)
@@ -140,7 +140,7 @@ void ShellBrowserMainParts::PostMainMess
 }
 
 void ShellBrowserMainParts::PreEarlyInitialization() {
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
