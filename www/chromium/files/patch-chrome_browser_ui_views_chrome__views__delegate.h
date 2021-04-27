--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2021-04-14 18:40:55 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -50,7 +50,7 @@ class ChromeViewsDelegate : public views::ViewsDelegat
                              base::OnceClosure callback) override;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
