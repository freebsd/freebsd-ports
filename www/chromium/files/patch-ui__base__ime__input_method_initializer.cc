--- ui/base/ime/input_method_initializer.cc.orig	2015-04-14 18:18:59.000000000 -0400
+++ ui/base/ime/input_method_initializer.cc	2015-04-28 08:56:59.070063000 -0400
@@ -6,14 +6,14 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/base/ime/chromeos/ime_bridge.h"
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "base/logging.h"
 #include "ui/base/ime/linux/fake_input_method_context_factory.h"
 #endif
 
 namespace {
 
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 const ui::LinuxInputMethodContextFactory* g_linux_input_method_context_factory;
 #endif
 
@@ -36,7 +36,7 @@
 void InitializeInputMethodForTesting() {
 #if defined(OS_CHROMEOS)
   chromeos::IMEBridge::Initialize();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   if (!g_linux_input_method_context_factory)
     g_linux_input_method_context_factory = new FakeInputMethodContextFactory();
   const LinuxInputMethodContextFactory* factory =
@@ -52,7 +52,7 @@
 void ShutdownInputMethodForTesting() {
 #if defined(OS_CHROMEOS)
   chromeos::IMEBridge::Shutdown();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   const LinuxInputMethodContextFactory* factory =
       LinuxInputMethodContextFactory::instance();
   CHECK(!factory || factory == g_linux_input_method_context_factory)
