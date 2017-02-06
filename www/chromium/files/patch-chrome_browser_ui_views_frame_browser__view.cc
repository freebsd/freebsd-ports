--- chrome/browser/ui/views/frame/browser_view.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1913,7 +1913,7 @@ void BrowserView::OnThemeChanged() {
 #endif
 #if defined(OS_WIN)
     ui::NativeThemeWin::instance()->NotifyObservers();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     ui::NativeThemeAura::instance()->NotifyObservers();
 #endif
   }
