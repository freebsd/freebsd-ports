--- Telegram/SourceFiles/platform/linux/linux_libs.cpp.orig	2018-12-24 08:16:05 UTC
+++ Telegram/SourceFiles/platform/linux/linux_libs.cpp
@@ -121,6 +121,7 @@ bool setupGtkBase(QLibrary &lib_gtk) {
 	return true;
 }
 
+#ifdef HAVE_APPINDICATOR
 bool setupAppIndicator(QLibrary &lib_indicator) {
 	if (!load(lib_indicator, "app_indicator_new", app_indicator_new)) return false;
 	if (!load(lib_indicator, "app_indicator_set_status", app_indicator_set_status)) return false;
@@ -130,6 +131,7 @@ bool setupAppIndicator(QLibrary &lib_ind
 	DEBUG_LOG(("Library appindicator functions loaded!"));
 	return true;
 }
+#endif
 #endif // !TDESKTOP_DISABLE_GTK_INTEGRATION
 
 } // namespace
@@ -191,10 +193,12 @@ f_g_type_check_instance_cast g_type_chec
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
@@ -234,6 +238,7 @@ void start() {
 	bool gtkLoaded = false;
 	bool indicatorLoaded = false;
 	QLibrary lib_gtk, lib_indicator;
+#ifdef HAVE_APPINDICATOR
 	if (loadLibrary(lib_indicator, "ayatana-appindicator3", 1) || loadLibrary(lib_indicator, "appindicator3", 1)) {
 		if (loadLibrary(lib_gtk, "gtk-3", 0)) {
 			gtkLoaded = setupGtkBase(lib_gtk);
@@ -249,6 +254,7 @@ void start() {
 			}
 		}
 	}
+#endif
 
 	// If no appindicator, try at least load gtk.
 	if (!gtkLoaded && !indicatorLoaded) {
