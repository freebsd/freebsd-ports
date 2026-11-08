--- plugins/obs-browser/panel/browser-panel-internal.hpp.orig	2026-08-14 22:07:07 UTC
+++ plugins/obs-browser/panel/browser-panel-internal.hpp
@@ -54,7 +54,7 @@ public:
 	void finishCloseBrowser();
 	void Resize();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 private:
 	bool needsDeleteXdndProxy = true;
 	void unsetToplevelXdndProxy();
