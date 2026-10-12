--- plugins/obs-browser/panel/browser-panel.cpp.orig	2026-08-14 22:07:07 UTC
+++ plugins/obs-browser/panel/browser-panel.cpp
@@ -233,7 +233,7 @@ void QCefWidgetInternal::closeBrowser()
 	cefBrowser = nullptr;
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static bool XWindowHasAtom(Display *display, Window w, Atom a)
 {
 	Atom type;
@@ -341,7 +341,7 @@ void QCefWidgetInternal::Init()
 								       cefBrowserSettings,
 								       CefRefPtr<CefDictionaryValue>(), rqc);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 			QueueCEFTask([this]() { unsetToplevelXdndProxy(); });
 #endif
 		});
