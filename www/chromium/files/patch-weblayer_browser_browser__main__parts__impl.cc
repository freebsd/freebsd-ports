--- weblayer/browser/browser_main_parts_impl.cc.orig	2019-10-30 16:40:04 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -34,7 +34,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -70,7 +70,7 @@ int BrowserMainPartsImpl::PreEarlyInitialization() {
 #if defined(USE_X11)
   ui::SetDefaultX11ErrorHandlers();
 #endif
-#if defined(USE_AURA) && defined(OS_LINUX)
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
