--- ui/base/ime/input_method_initializer.cc.orig	2016-01-21 16:55:32.692891135 +0100
+++ ui/base/ime/input_method_initializer.cc	2016-01-21 16:56:57.764073061 +0100
@@ -6,14 +6,14 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/base/ime/ime_bridge.h"
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
   IMEBridge::Initialize();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   if (!g_linux_input_method_context_factory)
     g_linux_input_method_context_factory = new FakeInputMethodContextFactory();
   const LinuxInputMethodContextFactory* factory =
