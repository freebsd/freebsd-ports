--- Telegram/lib_base/base/platform/linux/base_file_utilities_linux.cpp.orig	2021-01-28 15:30:24 UTC
+++ Telegram/lib_base/base/platform/linux/base_file_utilities_linux.cpp
@@ -114,7 +114,7 @@ bool ShowInFolder(const QString &filepath) {
 	}
 
 	if (g_app_info_launch_default_for_uri(
-		g_filename_to_uri(absoluteDirPath.toUtf8(), nullptr, nullptr),
+		g_filename_to_uri(absoluteDirPath.toUtf8().constData(), nullptr, nullptr),
 		nullptr,
 		nullptr)) {
 		return true;
