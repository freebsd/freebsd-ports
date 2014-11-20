--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -36,7 +36,7 @@
 #if defined(OS_WIN)
   virtual HICON GetDefaultWindowIcon() const OVERRIDE;
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const OVERRIDE;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const OVERRIDE;
 #endif
 
@@ -49,7 +49,7 @@
   virtual void OnBeforeWidgetInit(
       views::Widget::InitParams* params,
       views::internal::NativeWidgetDelegate* delegate) OVERRIDE;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   virtual bool WindowManagerProvidesTitleBar(bool maximized) OVERRIDE;
 #endif
 #if defined(USE_AURA)
