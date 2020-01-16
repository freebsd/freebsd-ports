--- chrome/browser/themes/theme_service_factory.cc.orig	2019-12-16 21:51:24 UTC
+++ chrome/browser/themes/theme_service_factory.cc
@@ -20,7 +20,7 @@
 
 #if defined(OS_WIN)
 #include "chrome/browser/themes/theme_service_win.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
@@ -64,7 +64,7 @@ KeyedService* ThemeServiceFactory::BuildServiceInstanc
   ThemeService* provider = NULL;
 #if defined(OS_WIN)
   provider = new ThemeServiceWin;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   provider = new ThemeServiceAuraLinux;
 #else
   provider = new ThemeService;
@@ -76,7 +76,7 @@ KeyedService* ThemeServiceFactory::BuildServiceInstanc
 
 void ThemeServiceFactory::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool default_uses_system_theme = false;
 
   const views::LinuxUI* linux_ui = views::LinuxUI::instance();
