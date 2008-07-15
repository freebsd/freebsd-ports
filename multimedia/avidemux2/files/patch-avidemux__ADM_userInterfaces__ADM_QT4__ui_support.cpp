--- ./avidemux/ADM_userInterfaces/ADM_QT4/ui_support.cpp.orig	2008-03-28 20:02:18.000000000 +0100
+++ ./avidemux/ADM_userInterfaces/ADM_QT4/ui_support.cpp	2008-07-10 17:16:26.000000000 +0200
@@ -38,10 +38,8 @@
 {
 	printf("\n[Locale] Locale: %s\n", QLocale::system().name().toUtf8().constData());
 
-	QString appdir = QCoreApplication::applicationDirPath() + "/i18n/";
-
-	loadTranslation(&qtTranslator, appdir + "qt_" + QLocale::system().name());
-	loadTranslation(&avidemuxTranslator, appdir + "avidemux_" + QLocale::system().name());
+	loadTranslation(&qtTranslator, "%%DATADIR%%/qt_" + QLocale::system().name());
+	loadTranslation(&avidemuxTranslator, "%%DATADIR%%/avidemux_" + QLocale::system().name());
 
 	printf("[Locale] Test: &Edit -> %s\n\n", HIDE_STRING_FROM_QT("MainWindow", "&Edit").toUtf8().data());
 }
