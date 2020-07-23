--- chrome/test/base/interactive_ui_tests_main.cc.orig	2020-04-06 07:47:38 UTC
+++ chrome/test/base/interactive_ui_tests_main.cc
@@ -16,7 +16,7 @@
 #if defined(USE_AURA)
 #include "ui/aura/test/ui_controls_factory_aura.h"
 #include "ui/base/test/ui_controls_aura.h"
-#if defined(USE_OZONE) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_OZONE) && ((defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD))
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 #if defined(USE_X11)
@@ -54,11 +54,11 @@ class InteractiveUITestSuite : public ChromeTestSuite 
     com_initializer_.reset(new base::win::ScopedCOMInitializer());
     ui_controls::InstallUIControlsAura(
         aura::test::CreateUIControlsAura(nullptr));
-#elif defined(USE_OZONE) && defined(OS_LINUX)
+#elif defined(USE_OZONE) && (defined(OS_LINUX) || defined(OS_BSD))
     ui::OzonePlatform::InitParams params;
     params.single_process = true;
     ui::OzonePlatform::InitializeForUI(params);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     ui_controls::InstallUIControlsAura(
         views::test::CreateUIControlsDesktopAura());
 #else
