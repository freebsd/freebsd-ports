--- weblayer/browser/browser_main_parts_impl.cc.orig	2021-01-18 21:29:49 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -68,7 +68,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -191,7 +191,7 @@ void BrowserMainPartsImpl::PreMainMessageLoopStart() {
 int BrowserMainPartsImpl::PreEarlyInitialization() {
   browser_process_ = std::make_unique<BrowserProcess>(std::move(local_state_));
 
-#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
