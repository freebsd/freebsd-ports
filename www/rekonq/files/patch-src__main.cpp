--- src/main.cpp	2011-04-03 12:26:13.000000000 +0400
+++ src/main.cpp	2011-04-05 00:05:26.578186110 +0400
@@ -207,7 +207,7 @@
 
 #if defined(Q_WS_X11)
     // On X11, the raster engine gives better performance than native.
-    QApplication::setGraphicsSystem(QL1S("raster"));
+//    QApplication::setGraphicsSystem(QL1S("raster"));
 #endif
 
     Application app;
