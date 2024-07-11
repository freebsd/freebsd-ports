--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkitgtk_library.cpp.orig	2024-06-07 13:31:52 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkitgtk_library.cpp
@@ -12,10 +12,10 @@ namespace Webview::WebKitGTK::Library {
 
 ResolveResult Resolve(bool wayland) {
 	const auto lib = (wayland
-			? base::Platform::LoadLibrary("libwebkitgtk-6.0.so.4", RTLD_NODELETE)
+			? base::Platform::LoadLibrary("libwebkitgtk-6.0.so", RTLD_NODELETE)
 			: nullptr)
-		?: base::Platform::LoadLibrary("libwebkit2gtk-4.1.so.0", RTLD_NODELETE)
-		?: base::Platform::LoadLibrary("libwebkit2gtk-4.0.so.37", RTLD_NODELETE);
+		?: base::Platform::LoadLibrary("libwebkit2gtk-4.1.so", RTLD_NODELETE)
+		?: base::Platform::LoadLibrary("libwebkit2gtk-4.0.so", RTLD_NODELETE);
 	const auto result = lib
 		&& LOAD_LIBRARY_SYMBOL(lib, gtk_init_check)
 		&& LOAD_LIBRARY_SYMBOL(lib, gtk_widget_get_type)
