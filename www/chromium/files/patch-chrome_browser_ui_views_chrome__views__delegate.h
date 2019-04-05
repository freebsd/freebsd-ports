--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -44,7 +44,7 @@ class ChromeViewsDelegate : public views::ViewsDelegat
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              const base::Closure& callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
