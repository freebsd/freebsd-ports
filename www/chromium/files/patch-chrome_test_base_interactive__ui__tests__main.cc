--- chrome/test/base/interactive_ui_tests_main.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/test/base/interactive_ui_tests_main.cc
@@ -16,7 +16,7 @@
 #if defined(USE_AURA)
 #include "ui/aura/test/ui_controls_factory_aura.h"
 #include "ui/base/test/ui_controls_aura.h"
-#if defined(USE_OZONE) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_OZONE) && ((defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD))
 #include "ui/base/ui_base_features.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -53,7 +53,7 @@ class InteractiveUITestSuite : public ChromeTestSuite 
     com_initializer_.reset(new base::win::ScopedCOMInitializer());
     ui_controls::InstallUIControlsAura(
         aura::test::CreateUIControlsAura(nullptr));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #if defined(USE_OZONE)
     if (features::IsUsingOzonePlatform()) {
       ui::OzonePlatform::InitParams params;
