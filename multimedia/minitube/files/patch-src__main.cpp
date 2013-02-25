--- ./src/main.cpp.orig	2013-02-03 20:19:43.000000000 +0000
+++ ./src/main.cpp	2013-02-22 20:30:39.321732617 +0000
@@ -11,7 +11,7 @@
 #include "mac_startup.h"
 #endif
 
-#ifdef Q_WS_X11
+#if defined(Q_WS_X11) && !defined(QT_NO_STYLE_GTK)
 QString getThemeName() {
     QString themeName;
 
@@ -82,12 +82,14 @@
 #ifndef Q_WS_X11
     Extra::appSetup(&app);
 #else
+#if !defined(QT_NO_STYLE_GTK)
     bool isGtk = app.style()->metaObject()->className() == QLatin1String("QGtkStyle");
     if (isGtk) {
         app.setProperty("gtk", isGtk);
         QString themeName = getThemeName();
         app.setProperty("style", themeName);
     }
+#endif
     QFile cssFile(":/style.css");
     cssFile.open(QFile::ReadOnly);
     QString styleSheet = QLatin1String(cssFile.readAll());
