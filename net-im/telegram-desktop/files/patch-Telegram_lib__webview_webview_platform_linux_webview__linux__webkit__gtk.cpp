--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp.orig	2021-04-14 05:42:51 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.cpp
@@ -26,7 +26,7 @@ bool Resolve() {
 	auto &gtk = BaseGtkIntegration::Instance()->library();
 
 	auto webkit2gtk = QLibrary();
-	const auto result =  LOAD_GTK_SYMBOL(gtk, gtk_widget_get_type)
+	const auto result = LOAD_GTK_SYMBOL(gtk, gtk_widget_get_type)
 		&& LOAD_GTK_SYMBOL(gtk, gtk_widget_grab_focus)
 		&& LOAD_GTK_SYMBOL(gtk, gtk_container_get_type)
 		&& LOAD_GTK_SYMBOL(gtk, gtk_container_add)
@@ -38,7 +38,7 @@ bool Resolve() {
 		&& LOAD_GTK_SYMBOL(gtk, gtk_window_get_type)
 		&& LOAD_GTK_SYMBOL(gtk, gtk_window_set_decorated)
 		&& LOAD_GTK_SYMBOL(gtk, gdk_x11_window_get_xid)
-		&& base::Platform::Gtk::LoadLibrary(webkit2gtk, "libwebkit2gtk-4.0.so.37", 0)
+		&& base::Platform::Gtk::LoadGtkLibrary(webkit2gtk, "libwebkit2gtk-4.0.so.37")
 		&& LOAD_GTK_SYMBOL(webkit2gtk, webkit_web_view_new)
 		&& LOAD_GTK_SYMBOL(webkit2gtk, webkit_web_view_get_type)
 		&& LOAD_GTK_SYMBOL(webkit2gtk, webkit_web_view_get_user_content_manager)
