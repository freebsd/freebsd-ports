--- content/public/test/content_browser_test.cc.orig	2021-09-14 01:51:57 UTC
+++ content/public/test/content_browser_test.cc
@@ -30,7 +30,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -93,7 +93,7 @@ void ContentBrowserTest::SetUp() {
   // LinuxInputMethodContextFactory has to be initialized.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
   ui::InitializeInputMethodForTesting();
 #endif
 
@@ -108,7 +108,7 @@ void ContentBrowserTest::TearDown() {
   // LinuxInputMethodContextFactory has to be shutdown.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
   ui::ShutdownInputMethodForTesting();
 #endif
 }
