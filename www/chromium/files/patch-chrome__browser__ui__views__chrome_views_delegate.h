--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2015-01-21 20:28:16 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -35,7 +35,7 @@
 #if defined(OS_WIN)
   virtual HICON GetDefaultWindowIcon() const override;
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
 
@@ -48,7 +48,7 @@
   void OnBeforeWidgetInit(
       views::Widget::InitParams* params,
       views::internal::NativeWidgetDelegate* delegate) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
 #if defined(USE_AURA)
