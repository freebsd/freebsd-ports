--- ./src/main.cpp.orig	2010-10-05 18:03:58.000000000 +0400
+++ ./src/main.cpp	2010-11-07 16:58:54.850117314 +0300
@@ -191,7 +191,7 @@
     }
 #if defined(Q_WS_X11)
     // On X11, the raster engine gives better performance than native.
-    QApplication::setGraphicsSystem(QString::fromLatin1("raster"));
+    // QApplication::setGraphicsSystem(QString::fromLatin1("raster"));
 #endif
     Application app;
 
