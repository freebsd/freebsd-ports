--- src/3rdparty/chromium/ui/base/x/x11_cursor_factory.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/base/x/x11_cursor_factory.cc
@@ -56,7 +56,7 @@ void X11CursorFactory::ObserveThemeChanges() {
 }
 
 void X11CursorFactory::ObserveThemeChanges() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = LinuxUi::instance();
   DCHECK(linux_ui);
   cursor_theme_observation_.Observe(linux_ui);
