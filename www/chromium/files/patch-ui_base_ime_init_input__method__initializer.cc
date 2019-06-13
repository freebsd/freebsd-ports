--- ui/base/ime/init/input_method_initializer.cc.orig	2019-06-04 18:55:49 UTC
+++ ui/base/ime/init/input_method_initializer.cc
@@ -8,7 +8,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/base/ime/ime_bridge.h"
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "base/logging.h"
 #include "ui/base/ime/linux/fake_input_method_context_factory.h"
 #elif defined(OS_WIN)
@@ -18,7 +18,7 @@
 
 namespace {
 
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 const ui::LinuxInputMethodContextFactory*
     g_linux_input_method_context_factory_for_testing;
 #endif
@@ -46,7 +46,7 @@ void ShutdownInputMethod() {
 void InitializeInputMethodForTesting() {
 #if defined(OS_CHROMEOS)
   IMEBridge::Initialize();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   if (!g_linux_input_method_context_factory_for_testing)
     g_linux_input_method_context_factory_for_testing =
         new FakeInputMethodContextFactory();
@@ -67,7 +67,7 @@ void InitializeInputMethodForTesting() {
 void ShutdownInputMethodForTesting() {
 #if defined(OS_CHROMEOS)
   IMEBridge::Shutdown();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   const LinuxInputMethodContextFactory* factory =
       LinuxInputMethodContextFactory::instance();
   CHECK(!factory || factory == g_linux_input_method_context_factory_for_testing)
