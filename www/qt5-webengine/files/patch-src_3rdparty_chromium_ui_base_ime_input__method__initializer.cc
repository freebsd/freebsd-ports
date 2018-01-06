--- src/3rdparty/chromium/ui/base/ime/input_method_initializer.cc.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/base/ime/input_method_initializer.cc
@@ -8,14 +8,14 @@
 
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
 
@@ -38,7 +38,7 @@ void ShutdownInputMethod() {
 void InitializeInputMethodForTesting() {
 #if defined(OS_CHROMEOS)
   IMEBridge::Initialize();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   if (!g_linux_input_method_context_factory)
     g_linux_input_method_context_factory = new FakeInputMethodContextFactory();
   const LinuxInputMethodContextFactory* factory =
@@ -54,7 +54,7 @@ void InitializeInputMethodForTesting() {
 void ShutdownInputMethodForTesting() {
 #if defined(OS_CHROMEOS)
   IMEBridge::Shutdown();
-#elif defined(USE_AURA) && defined(OS_LINUX)
+#elif defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD)) 
   const LinuxInputMethodContextFactory* factory =
       LinuxInputMethodContextFactory::instance();
   CHECK(!factory || factory == g_linux_input_method_context_factory)
