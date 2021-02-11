--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	2021-01-28 15:30:24 UTC
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp
@@ -14,11 +14,6 @@
 #include <QtCore/QDate>
 #include <QtGui/QGuiApplication>
 
-// this file is used on both Linux & BSD
-#ifdef Q_OS_LINUX
-#include <gnu/libc-version.h>
-#endif // Q_OS_LINUX
-
 namespace Platform {
 namespace {
 
@@ -103,7 +98,7 @@ QString SystemVersionPretty() {
 	static const auto result = [&] {
 		QStringList resultList{};
 
-#ifdef Q_OS_LINUX
+#if 0
 		resultList << "Linux";
 #else // Q_OS_LINUX
 		resultList << QSysInfo::kernelType();
@@ -186,7 +181,7 @@ QString AutoUpdateKey() {
 }
 
 QString GetLibcName() {
-#ifdef Q_OS_LINUX
+#if 0
 	return "glibc";
 #endif // Q_OS_LINUX
 
@@ -194,7 +189,7 @@ QString GetLibcName() {
 }
 
 QString GetLibcVersion() {
-#ifdef Q_OS_LINUX
+#if 0
 	static const auto result = [&] {
 		const auto version = QString::fromLatin1(gnu_get_libc_version());
 		return QVersionNumber::fromString(version).isNull() ? QString() : version;
