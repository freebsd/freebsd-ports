--- weblayer/browser/browser_main_parts_impl.cc.orig	2021-04-14 18:41:39 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -75,7 +75,7 @@
 #endif
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -192,7 +192,7 @@ int BrowserMainPartsImpl::PreEarlyInitialization() {
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
