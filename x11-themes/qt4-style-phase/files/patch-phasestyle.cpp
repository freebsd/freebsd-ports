--- phasestyle.cpp.orig	2007-05-03 08:48:44.000000000 +0400
+++ phasestyle.cpp	2010-11-26 05:07:37.000000000 +0300
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
