--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	2020-10-20 16:29:09 UTC
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp
@@ -11,7 +11,6 @@
 #include <QtCore/QVersionNumber>
 #include <QtCore/QDate>
 #include <QtGui/QGuiApplication>
-#include <gnu/libc-version.h>
 
 namespace Platform {
 
@@ -32,11 +31,9 @@ QString SystemVersionPretty() {
 	const auto value = result ? QString::fromLatin1(result) : QString();
 	const auto list = value.split(':', QString::SkipEmptyParts);
 
-	return "Linux "
+	return "FreeBSD "
 		+ (list.isEmpty() ? QString() : list[0] + ' ')
-		+ (IsWayland() ? "Wayland " : "X11 ")
-		+ "glibc "
-		+ GetGlibCVersion();
+		+ (IsWayland() ? "Wayland " : "X11 ");
 }
 
 QString SystemCountry() {
@@ -54,10 +51,6 @@ QString SystemLanguage() {
 QDate WhenSystemBecomesOutdated() {
 	if (IsLinux32Bit()) {
 		return QDate(2020, 9, 1);
-	} else if (const auto version = GetGlibCVersion(); !version.isEmpty()) {
-		if (QVersionNumber::fromString(version) < QVersionNumber(2, 23)) {
-			return QDate(2020, 9, 1); // Older than Ubuntu 16.04.
-		}
 	}
 	return QDate();
 }
@@ -78,14 +71,6 @@ QString AutoUpdateKey() {
 	} else {
 		Unexpected("Platform in AutoUpdateKey.");
 	}
-}
-
-QString GetGlibCVersion() {
-	static const auto result = [&] {
-		const auto version = QString::fromLatin1(gnu_get_libc_version());
-		return QVersionNumber::fromString(version).isNull() ? QString() : version;
-	}();
-	return result;
 }
 
 bool IsWayland() {
