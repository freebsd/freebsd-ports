--- Telegram/SourceFiles/platform/linux/main_window_linux.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/platform/linux/main_window_linux.cpp
@@ -36,7 +36,9 @@ namespace {
 bool noQtTrayIcon = false, tryAppIndicator = false;
 bool useGtkBase = false, useAppIndicator = false, useStatusIcon = false, trayIconChecked = false, useUnityCount = false;
 
+#ifdef HAVE_APPINDICATOR
 AppIndicator *_trayIndicator = 0;
+#endif
 GtkStatusIcon *_trayIcon = 0;
 GtkWidget *_trayMenu = 0;
 GdkPixbuf *_trayPixbuf = 0;
@@ -274,7 +276,9 @@ void MainWindow::workmodeUpdated(DBIWork
 	if (mode == dbiwmWindowOnly) {
 		if (noQtTrayIcon) {
 			if (useAppIndicator) {
+#ifdef HAVE_APPINDICATOR
 				Libs::app_indicator_set_status(_trayIndicator, APP_INDICATOR_STATUS_PASSIVE);
+#endif
 			} else if (useStatusIcon) {
 				Libs::gtk_status_icon_set_visible(_trayIcon, false);
 			}
@@ -288,7 +292,9 @@ void MainWindow::workmodeUpdated(DBIWork
 	} else {
 		if (noQtTrayIcon) {
 			if (useAppIndicator) {
+#ifdef HAVE_APPINDICATOR
 				Libs::app_indicator_set_status(_trayIndicator, APP_INDICATOR_STATUS_ACTIVE);
+#endif
 			} else if (useStatusIcon) {
 				Libs::gtk_status_icon_set_visible(_trayIcon, true);
 			}
@@ -305,7 +311,9 @@ void MainWindow::psUpdateIndicator() {
 	if (iconFile.exists()) {
 		QByteArray path = QFile::encodeName(iconFile.absoluteFilePath()), name = QFile::encodeName(iconFile.fileName());
 		name = name.mid(0, name.size() - 4);
+#ifdef HAVE_APPINDICATOR
 		Libs::app_indicator_set_icon_full(_trayIndicator, path.constData(), name);
+#endif
 	} else {
 		useAppIndicator = false;
 	}
@@ -392,11 +400,15 @@ void MainWindow::LibsLoaded() {
 			&& (Libs::g_object_ref_sink != nullptr)
 			&& (Libs::g_object_unref != nullptr);
 
+#ifdef HAVE_APPINDICATOR
 	useAppIndicator = useGtkBase
 			&& (Libs::app_indicator_new != nullptr)
 			&& (Libs::app_indicator_set_status != nullptr)
 			&& (Libs::app_indicator_set_menu != nullptr)
 			&& (Libs::app_indicator_set_icon_full != nullptr);
+#else
+    useAppIndicator = false;
+#endif
 
 	if (tryAppIndicator && useGtkBase && useAppIndicator) {
 		noQtTrayIcon = true;
@@ -439,6 +451,7 @@ void MainWindow::psCreateTrayIcon() {
 		return;
 	}
 
+#ifdef HAVE_APPINDICATOR
 	if (useAppIndicator) {
 		DEBUG_LOG(("Trying to create AppIndicator"));
 		_trayMenu = Libs::gtk_menu_new();
@@ -469,6 +482,7 @@ void MainWindow::psCreateTrayIcon() {
 			useAppIndicator = false;
 		}
 	}
+#endif
 	if (useStatusIcon) {
 		if (Libs::gdk_init_check(0, 0)) {
 			if (!_trayMenu) _trayMenu = Libs::gtk_menu_new();
@@ -585,10 +599,12 @@ MainWindow::~MainWindow() {
 		Libs::g_object_unref(_trayMenu);
 		_trayMenu = nullptr;
 	}
+#ifdef HAVE_APPINDICATOR
 	if (_trayIndicator) {
 		Libs::g_object_unref(_trayIndicator);
 		_trayIndicator = nullptr;
 	}
+#endif
 #ifndef TDESKTOP_DISABLE_UNITY_INTEGRATION
 	if (_psUnityLauncherEntry) {
 		Libs::g_object_unref(_psUnityLauncherEntry);
