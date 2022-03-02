--- ui/base/ime/init/input_method_initializer.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/base/ime/init/input_method_initializer.cc
@@ -10,7 +10,7 @@
 #include "build/chromeos_buildflags.h"
 
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "base/check.h"
 #include "ui/base/ime/linux/fake_input_method_context_factory.h"
 #elif BUILDFLAG(IS_WIN)
@@ -20,7 +20,7 @@
 
 namespace {
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 const ui::LinuxInputMethodContextFactory*
     g_linux_input_method_context_factory_for_testing;
 #endif
@@ -43,7 +43,7 @@ void ShutdownInputMethod() {
 
 void InitializeInputMethodForTesting() {
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   if (!g_linux_input_method_context_factory_for_testing)
     g_linux_input_method_context_factory_for_testing =
         new FakeInputMethodContextFactory();
@@ -61,7 +61,7 @@ void InitializeInputMethodForTesting() {
 
 void ShutdownInputMethodForTesting() {
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   const LinuxInputMethodContextFactory* factory =
       LinuxInputMethodContextFactory::instance();
   CHECK(!factory || factory == g_linux_input_method_context_factory_for_testing)
