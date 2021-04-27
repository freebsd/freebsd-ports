--- ui/base/ime/init/input_method_initializer.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/base/ime/init/input_method_initializer.cc
@@ -11,7 +11,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "ui/base/ime/chromeos/ime_bridge.h"
-#elif defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#elif defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "base/check.h"
 #include "ui/base/ime/linux/fake_input_method_context_factory.h"
 #elif defined(OS_WIN)
@@ -21,7 +21,7 @@
 
 namespace {
 
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 const ui::LinuxInputMethodContextFactory*
     g_linux_input_method_context_factory_for_testing;
 #endif
@@ -49,7 +49,7 @@ void ShutdownInputMethod() {
 void InitializeInputMethodForTesting() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   IMEBridge::Initialize();
-#elif defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#elif defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   if (!g_linux_input_method_context_factory_for_testing)
     g_linux_input_method_context_factory_for_testing =
         new FakeInputMethodContextFactory();
@@ -68,7 +68,7 @@ void InitializeInputMethodForTesting() {
 void ShutdownInputMethodForTesting() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   IMEBridge::Shutdown();
-#elif defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#elif defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   const LinuxInputMethodContextFactory* factory =
       LinuxInputMethodContextFactory::instance();
   CHECK(!factory || factory == g_linux_input_method_context_factory_for_testing)
