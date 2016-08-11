--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -35,7 +35,7 @@ class ChromeViewsDelegate : public views
 #if defined(OS_WIN)
   HICON GetDefaultWindowIcon() const override;
   HICON GetSmallWindowIcon() const override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
 
@@ -48,7 +48,7 @@ class ChromeViewsDelegate : public views
   void OnBeforeWidgetInit(
       views::Widget::InitParams* params,
       views::internal::NativeWidgetDelegate* delegate) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
   ui::ContextFactory* GetContextFactory() override;
