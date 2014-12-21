--- phasestyle.cpp.orig	2007-05-03 08:48:44.000000000 +0400
+++ phasestyle.cpp	2014-12-15 02:02:43.000000000 +0300
@@ -2028,7 +2028,7 @@
           qreal cx = rect.center().x();
           qreal cy = rect.center().y();
           qreal radius = (qMin(w, h) / 2.0) - 2.0;
-          qreal tick = qMax(radius / 6, 4.0);
+          qreal tick = qMax(radius / 6, (qreal)4.0);
 
           if (dial->subControls & SC_DialGroove) {
               QRectF groove = QRectF(cx-radius+tick, cy-radius+tick,
@@ -2367,6 +2367,8 @@
           return 2;
 
       case PM_TabBarTabVSpace: {
+          if (!option)
+			  return QWindowsStyle::pixelMetric(metric, option, widget);
           const QStyleOptionTab *tab;
           tab = qstyleoption_cast<const QStyleOptionTab *>(option);
           if (tab) {
@@ -2380,10 +2382,14 @@
       }
 
       case PM_ProgressBarChunkWidth: {
+          if (!option)
+			  return QWindowsStyle::pixelMetric(metric, option, widget);
           int breadth = qMax(option->rect.width(), option->rect.height());
           return qMax(breadth / 10, 10);
       }
       case PM_TitleBarHeight:
+          if (!option)
+			  return QWindowsStyle::pixelMetric(metric, option, widget);
           return qMax(option->fontMetrics.lineSpacing(), 20);
 
       default:
