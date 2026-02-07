--- src/paintcanvas.cpp.orig	2021-02-15 21:19:18 UTC
+++ src/paintcanvas.cpp
@@ -24,6 +24,7 @@
 
 #include <QImage>
 #include <QPainter>
+#include <QPainterPath>
 #include <QVariant>
 
 PaintCanvas::PaintCanvas(QWidget *parent)
