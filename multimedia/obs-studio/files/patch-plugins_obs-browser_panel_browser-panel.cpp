--- plugins/obs-browser/panel/browser-panel.cpp.orig	2026-10-29 21:06:38 UTC
+++ plugins/obs-browser/panel/browser-panel.cpp
@@ -238,7 +238,7 @@ void QCefWidgetInternal::closeBrowser()
 	cefBrowser = nullptr;
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static bool XWindowHasAtom(Display *display, Window w, Atom a)
 {
 	Atom type;
@@ -353,7 +353,7 @@ void QCefWidgetInternal::Init()
 								       cefBrowserSettings,
 								       CefRefPtr<CefDictionaryValue>(), rqc);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 			QueueCEFTask([this]() { unsetToplevelXdndProxy(); });
 #endif
 		});
