--- pdf_viewer/main.cpp.orig	2023-03-04 14:34:21 UTC
+++ pdf_viewer/main.cpp
@@ -296,7 +296,7 @@ void configure_paths(){
 	user_config_paths.push_back(mac_standard_config_path.slash(L"prefs_user.config"));
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	QStringList all_config_paths = QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation);
 	for (int i = all_config_paths.size()-1; i >= 0; i--) {
 		user_config_paths.push_back(Path(all_config_paths.at(i).toStdWString()).slash(L"prefs_user.config"));
@@ -306,8 +306,8 @@ void configure_paths(){
 #ifdef LINUX_STANDARD_PATHS
 	Path home_path(QDir::homePath().toStdWString());
 	Path standard_data_path = home_path.slash(L".local").slash(L"share").slash(L"sioyek");
-	Path standard_config_path = Path(L"/etc/sioyek");
-	Path read_only_data_path = Path(L"/usr/share/sioyek");
+	Path standard_config_path = Path(L"%%ETCDIR%%");
+	Path read_only_data_path = Path(L"%%DATADIR%%");
 	standard_data_path.create_directories();
 
 	default_config_path = standard_config_path.slash(L"prefs.config");
