--- Telegram/SourceFiles/platform/linux/linux_libs.cpp.orig	2019-09-27 17:04:25 UTC
+++ Telegram/SourceFiles/platform/linux/linux_libs.cpp
@@ -128,6 +128,7 @@ bool setupGtkBase(QLibrary &lib_gtk) {
 	return true;
 }
 
+#ifdef HAVE_APPINDICATOR
 bool setupAppIndicator(QLibrary &lib_indicator) {
 	if (!load(lib_indicator, "app_indicator_new", app_indicator_new)) return false;
 	if (!load(lib_indicator, "app_indicator_set_status", app_indicator_set_status)) return false;
@@ -137,6 +138,7 @@ bool setupAppIndicator(QLibrary &lib_indicator) {
 	DEBUG_LOG(("Library appindicator functions loaded!"));
 	return true;
 }
+#endif
 #endif // !TDESKTOP_DISABLE_GTK_INTEGRATION
 
 } // namespace
@@ -198,10 +200,12 @@ f_g_type_check_instance_cast g_type_check_instance_cas
 f_g_type_check_instance_is_a g_type_check_instance_is_a = nullptr;
 f_g_signal_connect_data g_signal_connect_data = nullptr;
 f_g_signal_handler_disconnect g_signal_handler_disconnect = nullptr;
+#ifdef HAVE_APPINDICATOR
 f_app_indicator_new app_indicator_new = nullptr;
 f_app_indicator_set_status app_indicator_set_status = nullptr;
 f_app_indicator_set_menu app_indicator_set_menu = nullptr;
 f_app_indicator_set_icon_full app_indicator_set_icon_full = nullptr;
+#endif
 f_gdk_init_check gdk_init_check = nullptr;
 f_gdk_pixbuf_new_from_data gdk_pixbuf_new_from_data = nullptr;
 f_gdk_pixbuf_new_from_file gdk_pixbuf_new_from_file = nullptr;
@@ -237,6 +241,7 @@ void start() {
 	bool indicatorLoaded = false;
 	bool isWayland = QGuiApplication::platformName().startsWith(qsl("wayland"), Qt::CaseInsensitive);
 	QLibrary lib_gtk, lib_indicator;
+#ifdef HAVE_APPINDICATOR
 	if (loadLibrary(lib_indicator, "ayatana-appindicator3", 1) || loadLibrary(lib_indicator, "appindicator3", 1)) {
 		if (loadLibrary(lib_gtk, "gtk-3", 0)) {
 			gtkLoaded = setupGtkBase(lib_gtk);
@@ -252,6 +257,7 @@ void start() {
 			}
 		}
 	}
+#endif
 
 	// If no appindicator, try at least load gtk.
 	if (!gtkLoaded && !indicatorLoaded) {
