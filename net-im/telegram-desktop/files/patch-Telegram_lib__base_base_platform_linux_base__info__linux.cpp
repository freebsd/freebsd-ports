--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	2020-06-24 20:32:27.483667000 +0300
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp	2020-06-24 20:45:44.399296000 +0300
@@ -13,7 +13,6 @@
 #include <QtCore/QVersionNumber>
 #include <QtCore/QDate>
 #include <QtGui/QGuiApplication>
-#include <gnu/libc-version.h>
 
 namespace Platform {
 namespace {
@@ -72,11 +71,9 @@
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
@@ -92,13 +89,6 @@
 }
 
 QDate WhenSystemBecomesOutdated() {
-	if (IsLinux32Bit()) {
-		return QDate(2020, 9, 1);
-	} else if (const auto version = GetGlibCVersion(); !version.isEmpty()) {
-		if (QVersionNumber::fromString(version) < QVersionNumber(2, 23)) {
-			return QDate(2020, 9, 1); // Older than Ubuntu 16.04.
-		}
-	}
 	return QDate();
 }
 
@@ -120,14 +110,6 @@
 	}
 }
 
-QString GetGlibCVersion() {
-	static const auto result = [&] {
-		const auto version = QString::fromLatin1(gnu_get_libc_version());
-		return QVersionNumber::fromString(version).isNull() ? QString() : version;
-	}();
-	return result;
-}
-
 bool IsWayland() {
 	return QGuiApplication::platformName().startsWith("wayland", Qt::CaseInsensitive);
 }
