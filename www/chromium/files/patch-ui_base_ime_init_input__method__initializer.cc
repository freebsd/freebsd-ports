--- ui/base/ime/init/input_method_initializer.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/base/ime/init/input_method_initializer.cc
@@ -10,7 +10,7 @@
 #include "build/chromeos_buildflags.h"
 
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/linux/fake_input_method_context.h"
 #include "ui/base/ime/linux/linux_input_method_context_factory.h"
 #elif BUILDFLAG(IS_WIN)
@@ -34,7 +34,7 @@ void ShutdownInputMethod() {
 
 void InitializeInputMethodForTesting() {
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   GetInputMethodContextFactoryForTest() =
       base::BindRepeating([](LinuxInputMethodContextDelegate* delegate)
                               -> std::unique_ptr<LinuxInputMethodContext> {
@@ -47,7 +47,7 @@ void InitializeInputMethodForTesting() {
 
 void ShutdownInputMethodForTesting() {
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // The function owns the factory (as a static variable that's returned by
   // reference), so setting this to an empty factory will free the old one.
   GetInputMethodContextFactoryForTest() = LinuxInputMethodContextFactory();
