Fix build with Qt 6.10.1. The QString::arg() method no longer accepts
implicit conversions. [1]

[1] https://doc.qt.io/qt-6/qstring.html#arg-2

--- OMEdit/OMEditLIB/Modeling/ModelWidgetContainer.cpp.orig	2025-11-24 16:18:03 UTC
+++ OMEdit/OMEditLIB/Modeling/ModelWidgetContainer.cpp
@@ -3943,7 +3943,7 @@ void GraphicsView::getCoordinateSystemAndGraphics(QStr
   }
   // add the initial scale
   if (mCoordinateSystem.hasInitialScale()) {
-    coOrdinateSystemList.append(QString("initialScale=%1").arg(mCoordinateSystem.getInitialScale()));
+    coOrdinateSystemList.append(QString("initialScale=%1").arg(static_cast<int>(mCoordinateSystem.getInitialScale())));
   }
   // add the grid
   if (mCoordinateSystem.hasGrid()) {
