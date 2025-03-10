--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -52,7 +52,7 @@ class ChromeViewsDelegate : public views::ViewsDelegat
                              base::OnceClosure callback) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
