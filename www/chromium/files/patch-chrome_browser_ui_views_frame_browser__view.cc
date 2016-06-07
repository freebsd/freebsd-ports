--- chrome/browser/ui/views/frame/browser_view.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -187,7 +187,7 @@
 #include "content/public/common/mojo_shell_connection.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/native_theme/native_theme_dark_aura.h"
 #endif
 
@@ -2017,7 +2017,7 @@ void BrowserView::OnThemeChanged() {
 #if defined(OS_WIN)
     ui::NativeThemeDarkWin::instance()->NotifyObservers();
     ui::NativeThemeWin::instance()->NotifyObservers();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     ui::NativeThemeDarkAura::instance()->NotifyObservers();
     ui::NativeThemeAura::instance()->NotifyObservers();
 #endif
