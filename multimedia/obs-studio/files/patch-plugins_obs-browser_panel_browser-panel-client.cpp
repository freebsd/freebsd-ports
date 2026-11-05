--- plugins/obs-browser/panel/browser-panel-client.cpp.orig	2026-10-29 21:06:38 UTC
+++ plugins/obs-browser/panel/browser-panel-client.cpp
@@ -121,7 +121,7 @@ void QCefBrowserClient::OnTitleChange(CefRefPtr<CefBro
 		CefWindowHandle handl = browser->GetHost()->GetWindowHandle();
 		std::wstring str_title = newTitle;
 		SetWindowTextW((HWND)handl, str_title.c_str());
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 		CefWindowHandle handl = browser->GetHost()->GetWindowHandle();
 		XStoreName(cef_get_xdisplay(), handl, newTitle.ToString().c_str());
 #endif
