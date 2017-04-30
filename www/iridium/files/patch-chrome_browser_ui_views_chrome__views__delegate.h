--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -43,7 +43,7 @@ class ChromeViewsDelegate : public views
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              const base::Closure& callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
