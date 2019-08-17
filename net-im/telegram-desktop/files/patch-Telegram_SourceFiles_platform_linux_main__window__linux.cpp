--- Telegram/SourceFiles/platform/linux/main_window_linux.cpp.orig	2019-07-07 13:34:35 UTC
+++ Telegram/SourceFiles/platform/linux/main_window_linux.cpp
@@ -25,7 +25,9 @@ bool noQtTrayIcon = false, tryAppIndicator = false;
 bool useGtkBase = false, useAppIndicator = false, useStatusIcon = false, trayIconChecked = false, useUnityCount = false;
 
 #ifndef TDESKTOP_DISABLE_GTK_INTEGRATION
+#ifdef HAVE_APPINDICATOR
 AppIndicator *_trayIndicator = 0;
+#endif
 GtkStatusIcon *_trayIcon = 0;
 GtkWidget *_trayMenu = 0;
 GdkPixbuf *_trayPixbuf = 0;
@@ -291,7 +293,9 @@ void MainWindow::workmodeUpdated(DBIWorkMode mode) {
 		if (noQtTrayIcon) {
 #ifndef TDESKTOP_DISABLE_GTK_INTEGRATION
 			if (useAppIndicator) {
+#ifdef HAVE_APPINDICATOR
 				Libs::app_indicator_set_status(_trayIndicator, APP_INDICATOR_STATUS_PASSIVE);
+#endif
 			} else if (useStatusIcon) {
 				Libs::gtk_status_icon_set_visible(_trayIcon, false);
 			}
@@ -307,7 +311,9 @@ void MainWindow::workmodeUpdated(DBIWorkMode mode) {
 		if (noQtTrayIcon) {
 #ifndef TDESKTOP_DISABLE_GTK_INTEGRATION
 			if (useAppIndicator) {
+#ifdef HAVE_APPINDICATOR
 				Libs::app_indicator_set_status(_trayIndicator, APP_INDICATOR_STATUS_ACTIVE);
+#endif
 			} else if (useStatusIcon) {
 				Libs::gtk_status_icon_set_visible(_trayIcon, true);
 			}
@@ -326,7 +332,9 @@ void MainWindow::psUpdateIndicator() {
 	if (iconFile.exists()) {
 		QByteArray path = QFile::encodeName(iconFile.absoluteFilePath()), name = QFile::encodeName(iconFile.fileName());
 		name = name.mid(0, name.size() - 4);
+#ifdef HAVE_APPINDICATOR
 		Libs::app_indicator_set_icon_full(_trayIndicator, path.constData(), name);
+#endif
 	} else {
 		useAppIndicator = false;
 	}
@@ -423,11 +431,15 @@ void MainWindow::LibsLoaded() {
 			&& (Libs::g_object_ref_sink != nullptr)
 			&& (Libs::g_object_unref != nullptr);
 
+#ifdef HAVE_APPINDICATOR
 	useAppIndicator = useGtkBase
 			&& (Libs::app_indicator_new != nullptr)
 			&& (Libs::app_indicator_set_status != nullptr)
 			&& (Libs::app_indicator_set_menu != nullptr)
 			&& (Libs::app_indicator_set_icon_full != nullptr);
+#else
+	useAppIndicator = false;
+#endif
 
 	if (tryAppIndicator && useGtkBase && useAppIndicator) {
 		noQtTrayIcon = true;
@@ -463,6 +475,7 @@ void MainWindow::psCreateTrayIcon() {
 	}
 
 #ifndef TDESKTOP_DISABLE_GTK_INTEGRATION
+#ifdef HAVE_APPINDICATOR
 	if (useAppIndicator) {
 		DEBUG_LOG(("Trying to create AppIndicator"));
 		_trayMenu = Libs::gtk_menu_new();
@@ -493,6 +506,7 @@ void MainWindow::psCreateTrayIcon() {
 			useAppIndicator = false;
 		}
 	}
+#endif
 	if (useStatusIcon) {
 		if (Libs::gdk_init_check(0, 0)) {
 			if (!_trayMenu) _trayMenu = Libs::gtk_menu_new();
@@ -617,10 +631,12 @@ MainWindow::~MainWindow() {
 		Libs::g_object_unref(_trayMenu);
 		_trayMenu = nullptr;
 	}
+#ifdef HAVE_APPINDICATOR
 	if (_trayIndicator) {
 		Libs::g_object_unref(_trayIndicator);
 		_trayIndicator = nullptr;
 	}
+#endif
 #endif // !TDESKTOP_DISABLE_GTK_INTEGRATION
 }
 
