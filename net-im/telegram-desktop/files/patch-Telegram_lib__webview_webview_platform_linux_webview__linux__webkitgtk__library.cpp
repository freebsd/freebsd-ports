--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkitgtk_library.cpp.orig	2026-10-08 19:07:02 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkitgtk_library.cpp
@@ -11,9 +11,9 @@ ResolveResult Resolve(Platform platform) {
 namespace Webview::WebKitGTK::Library {
 
 ResolveResult Resolve(Platform platform) {
-	const auto lib = base::Platform::LoadLibrary("libwebkitgtk-6.0.so.4", RTLD_NODELETE)
-		?: base::Platform::LoadLibrary("libwebkit2gtk-4.1.so.0", RTLD_NODELETE)
-		?: base::Platform::LoadLibrary("libwebkit2gtk-4.0.so.37", RTLD_NODELETE);
+	const auto lib = base::Platform::LoadLibrary("libwebkitgtk-6.0.so", RTLD_NODELETE)
+		?: base::Platform::LoadLibrary("libwebkit2gtk-4.1.so", RTLD_NODELETE)
+		?: base::Platform::LoadLibrary("libwebkit2gtk-4.0.so", RTLD_NODELETE);
 	const auto result = lib
 		&& LOAD_LIBRARY_SYMBOL(lib, gtk_init_check)
 		&& LOAD_LIBRARY_SYMBOL(lib, gdk_set_allowed_backends)
