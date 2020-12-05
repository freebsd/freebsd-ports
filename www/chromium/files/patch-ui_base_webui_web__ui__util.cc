--- ui/base/webui/web_ui_util.cc.orig	2020-11-13 06:37:05 UTC
+++ ui/base/webui/web_ui_util.cc
@@ -34,7 +34,7 @@
 #include "base/win/windows_version.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "ui/base/ui_base_features.h"
 #endif
 
@@ -232,7 +232,7 @@ std::string GetFontFamily() {
 
 // TODO(dnicoara) Remove Ozone check when PlatformFont support is introduced
 // into Ozone: crbug.com/320050
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (!features::IsUsingOzonePlatform()) {
     font_family = ui::ResourceBundle::GetSharedInstance()
                       .GetFont(ui::ResourceBundle::BaseFont)
