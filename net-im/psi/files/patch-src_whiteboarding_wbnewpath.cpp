--- src/whiteboarding/wbnewpath.cpp.orig	2020-05-21 10:25:20 UTC
+++ src/whiteboarding/wbnewpath.cpp
@@ -23,6 +23,7 @@
 #include "../sxe/sxesession.h"
 
 #include <QGraphicsScene>
+#include <QPainterPath>
 
 WbNewPath::WbNewPath(QGraphicsScene* s, QPointF startPos, int strokeWidth, const QColor &strokeColor, const QColor &fillColor) : WbNewItem(s) {
 	controlPoint_ = 0;
