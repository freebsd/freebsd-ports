--- ./avidemux/ADM_userInterfaces/ADM_QT4/ui_support.cpp.orig	2008-09-24 05:09:49.000000000 +0400
+++ ./avidemux/ADM_userInterfaces/ADM_QT4/ui_support.cpp	2009-04-16 17:45:10.000000000 +0400
@@ -60,10 +60,8 @@
 {
 	printf("\n[Locale] Locale: %s\n", QLocale::system().name().toUtf8().constData());
 
-	QString appdir = QCoreApplication::applicationDirPath() + "/i18n/";
-
-	loadTranslation(&qtTranslator, appdir + "qt_" + QLocale::system().name());
-	loadTranslation(&avidemuxTranslator, appdir + "avidemux_" + QLocale::system().name());
+	loadTranslation(&qtTranslator, "%%DATADIR%%/qt_" + QLocale::system().name());
+	loadTranslation(&avidemuxTranslator, "%%DATADIR%%/avidemux_" + QLocale::system().name());
 	translatorLoaded = true;
 
 	// Re-translate existing map (to take care of global strings already allocated)
