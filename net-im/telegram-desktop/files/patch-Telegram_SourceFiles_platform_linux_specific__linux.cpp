--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	2024-04-05 17:15:54 UTC
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp
@@ -510,7 +510,7 @@ QString SingleInstanceLocalServerName(const QString &h
 
 #if QT_VERSION < QT_VERSION_CHECK(6, 5, 0)
 std::optional<bool> IsDarkMode() {
-	const auto result = base::Platform::XDP::ReadSetting(
+	auto result = base::Platform::XDP::ReadSetting(
 		"org.freedesktop.appearance",
 		"color-scheme");
 
