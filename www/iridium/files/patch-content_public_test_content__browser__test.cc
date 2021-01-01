--- content/public/test/content_browser_test.cc.orig	2020-04-06 08:25:58 UTC
+++ content/public/test/content_browser_test.cc
@@ -26,7 +26,7 @@
 #include "base/mac/foundation_util.h"
 #endif
 
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -83,7 +83,7 @@ void ContentBrowserTest::SetUp() {
 #endif
 
   // LinuxInputMethodContextFactory has to be initialized.
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
   ui::InitializeInputMethodForTesting();
 #endif
 
@@ -96,7 +96,7 @@ void ContentBrowserTest::TearDown() {
   BrowserTestBase::TearDown();
 
   // LinuxInputMethodContextFactory has to be shutdown.
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
   ui::ShutdownInputMethodForTesting();
 #endif
 }
