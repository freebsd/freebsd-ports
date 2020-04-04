--- Telegram/lib_base/base/platform/linux/base_info_linux.cpp.orig	2020-03-30 09:44:51 UTC
+++ Telegram/lib_base/base/platform/linux/base_info_linux.cpp
@@ -65,7 +65,7 @@ QString SystemVersionPretty() {
 	const auto result = getenv("XDG_CURRENT_DESKTOP");
 	const auto value = result ? QString::fromLatin1(result) : QString();
 	const auto list = value.split(':', QString::SkipEmptyParts);
-	return list.isEmpty() ? "Linux" : "Linux " + list[0];
+	return list.isEmpty() ? "FreeBSD" : "FreeBSD " + list[0];
 }
 
 QString SystemCountry() {
