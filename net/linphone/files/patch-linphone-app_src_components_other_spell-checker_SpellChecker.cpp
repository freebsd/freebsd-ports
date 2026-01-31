--- linphone-app/src/components/other/spell-checker/SpellChecker.cpp.orig	2025-12-26 08:15:07 UTC
+++ linphone-app/src/components/other/spell-checker/SpellChecker.cpp
@@ -35,7 +35,7 @@ SpellChecker::SpellChecker(QObject *parent) : QSyntaxH
 	errorFormater.setUnderlineColor(Qt::red); // not supported before Qt6.2
 	
 	QFontMetrics fm = QFontMetrics(CoreManager::getInstance()->getSettingsModel()->getTextMessageFont());
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	wave = QString("‾");
 	QRect boundingRect = fm.boundingRect(wave);
 	waveHeight = 10;
