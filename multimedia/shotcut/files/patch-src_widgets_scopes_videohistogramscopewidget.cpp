--- src/widgets/scopes/videohistogramscopewidget.cpp.orig	2020-05-21 10:09:23 UTC
+++ src/widgets/scopes/videohistogramscopewidget.cpp
@@ -19,6 +19,7 @@
 #include <Logger.h>
 #include <QMouseEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QToolTip>
 
 const qreal IRE0 = 16;
