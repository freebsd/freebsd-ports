--- ui/aura/test/aura_test_helper.cc.orig	2020-07-13 10:05:19 UTC
+++ ui/aura/test/aura_test_helper.cc
@@ -29,7 +29,7 @@
 #include "ui/wm/core/default_activation_client.h"
 #include "ui/wm/core/default_screen_position_client.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/platform_window/common/platform_window_defaults.h"  // nogncheck
 #endif
 
@@ -55,7 +55,7 @@ AuraTestHelper::AuraTestHelper(ui::ContextFactory* con
   DCHECK(!g_instance);
   g_instance = this;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ui::test::EnableTestConfigForPlatformWindows();
 #endif
 
