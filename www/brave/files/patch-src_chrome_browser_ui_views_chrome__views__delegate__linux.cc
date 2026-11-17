--- src/chrome/browser/ui/views/chrome_views_delegate_linux.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/chrome_views_delegate_linux.cc
@@ -44,7 +44,7 @@ bool WindowManagerDrawsTitleBarOverMaxim
   return desktop_env == base::nix::DESKTOP_ENVIRONMENT_UNITY;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 int GetWindowIconResourceId() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   switch (chrome::GetChannel()) {
@@ -102,7 +102,7 @@ views::NativeWidget* ChromeViewsDelegate
                               delegate);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::ImageSkia* ChromeViewsDelegate::GetDefaultWindowIcon() const {
   ui::ResourceBundle& rb = ui::ResourceBundle::GetSharedInstance();
   return rb.GetImageSkiaNamed(GetWindowIconResourceId());
