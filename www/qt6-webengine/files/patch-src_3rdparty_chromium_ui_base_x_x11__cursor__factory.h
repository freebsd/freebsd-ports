--- src/3rdparty/chromium/ui/base/x/x11_cursor_factory.h.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/ui/base/x/x11_cursor_factory.h
@@ -20,7 +20,7 @@ namespace ui {
 class X11Cursor;
 class XCursorLoader;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class LinuxUi;
 #endif
 
@@ -59,7 +59,7 @@ class COMPONENT_EXPORT(UI_BASE_X) X11CursorFactory
 
   std::map<mojom::CursorType, scoped_refptr<X11Cursor>> default_cursors_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<LinuxUi, CursorThemeManagerObserver>
       cursor_theme_observation_{this};
 #endif
