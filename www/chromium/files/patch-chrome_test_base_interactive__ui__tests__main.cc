--- chrome/test/base/interactive_ui_tests_main.cc.orig	2021-07-19 18:45:11 UTC
+++ chrome/test/base/interactive_ui_tests_main.cc
@@ -19,7 +19,7 @@
 #if defined(USE_AURA)
 #include "ui/aura/test/ui_controls_factory_aura.h"
 #include "ui/base/test/ui_controls_aura.h"
-#if defined(USE_OZONE) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_OZONE) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "ui/base/ui_base_features.h"
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/platform_window/common/platform_window_defaults.h"
@@ -57,7 +57,7 @@ class InteractiveUITestSuite : public ChromeTestSuite 
     com_initializer_ = std::make_unique<base::win::ScopedCOMInitializer>();
     ui_controls::InstallUIControlsAura(
         aura::test::CreateUIControlsAura(nullptr));
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #if defined(USE_OZONE)
     if (features::IsUsingOzonePlatform()) {
       // Notifies the platform that test config is needed. For Wayland, for
