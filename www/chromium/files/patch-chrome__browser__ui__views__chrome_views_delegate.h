--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2015-07-15 16:29:58.000000000 -0400
+++ chrome/browser/ui/views/chrome_views_delegate.h	2015-07-21 21:54:27.828544000 -0400
@@ -31,7 +31,7 @@
   HICON GetDefaultWindowIcon() const override;
   HICON GetSmallWindowIcon() const override;
   bool IsWindowInMetro(gfx::NativeWindow window) const override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
 
@@ -44,7 +44,7 @@
   void OnBeforeWidgetInit(
       views::Widget::InitParams* params,
       views::internal::NativeWidgetDelegate* delegate) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
   ui::ContextFactory* GetContextFactory() override;
