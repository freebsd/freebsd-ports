--- choqok/systrayicon.cpp.orig	2020-02-05 11:49:13 UTC
+++ choqok/systrayicon.cpp
@@ -81,7 +81,7 @@ void SysTrayIcon::updateUnreadCount(int changeOfUnread
 
         auto pointSize = f.pointSizeF();
         QFontMetrics fm(f);
-        int w = fm.width(countStr);
+        int w = fm.horizontalAdvance(countStr);
         if (w > (oldWidth - 2)) {
             pointSize *= float(oldWidth - 2) / float(w);
             f.setPointSizeF(pointSize);
