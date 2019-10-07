--- Telegram/SourceFiles/platform/freebsd/info_freebsd.cpp.orig	2019-09-29 04:23:33 UTC
+++ Telegram/SourceFiles/platform/freebsd/info_freebsd.cpp
@@ -0,0 +1,49 @@
+/*
+This file is part of Telegram Desktop,
+the official desktop application for the Telegram messaging service.
+
+For license and copyright information please follow this link:
+https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
+*/
+#include "platform/freebsd/info_freebsd.h"
+
+namespace Platform {
+
+QString DeviceModelPretty() {
+    return "FreeBSD";
+}
+
+QString SystemVersionPretty() {
+	const auto result = getenv("XDG_CURRENT_DESKTOP");
+	const auto value = result ? QString::fromLatin1(result) : QString();
+	const auto list = value.split(':', QString::SkipEmptyParts);
+	return list.isEmpty() ? "FreeBSD" : "FreeBSD " + list[0];
+}
+
+QString SystemCountry() {
+	return QLocale::system().name().split('_').last();
+}
+
+QString SystemLanguage() {
+	const auto system = QLocale::system();
+	const auto languages = system.uiLanguages();
+	return languages.isEmpty()
+		? system.name().split('_').first()
+		: languages.front();
+}
+
+QDate WhenSystemBecomesOutdated() {
+	return QDate();
+}
+
+int AutoUpdateVersion() {
+	return 2;
+}
+
+QString AutoUpdateKey() {
+    return "freebsd";
+}
+
+
+
+} // namespace Platform
