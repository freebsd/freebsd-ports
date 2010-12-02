--- ./src/main.cpp.orig	2010-09-27 06:42:17.000000000 +0400
+++ ./src/main.cpp	2010-11-07 17:02:53.153956800 +0300
@@ -28,7 +28,7 @@
     Q_INIT_RESOURCE(htmls);
     Q_INIT_RESOURCE(data);
 #ifdef Q_WS_X11
-    QApplication::setGraphicsSystem(QString::fromLatin1("raster"));
+    // QApplication::setGraphicsSystem(QString::fromLatin1("raster"));
 #endif
     BrowserApplication application(argc, argv);
     if (!application.isRunning())
