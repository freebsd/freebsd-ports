--- content/shell/browser/shell_browser_main_parts.cc.orig	2017-12-15 02:04:18.000000000 +0100
+++ content/shell/browser/shell_browser_main_parts.cc	2017-12-24 15:15:04.473424000 +0100
@@ -49,7 +49,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
 #include "ui/base/ime/input_method_initializer.h"
 #endif
 #if defined(OS_CHROMEOS)
@@ -133,7 +133,7 @@
 #if defined(USE_X11)
   ui::SetDefaultX11ErrorHandlers();
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
