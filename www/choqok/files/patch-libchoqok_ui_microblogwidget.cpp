--- libchoqok/ui/microblogwidget.cpp.orig	2020-02-05 11:49:13 UTC
+++ libchoqok/ui/microblogwidget.cpp
@@ -65,7 +65,7 @@ QIcon addNumToIcon(const QIcon &big , int number , con
         painter.setFont(font);
 
         QString numberStr = QString::number(number);
-        int textWidth = painter.fontMetrics().width(numberStr) + 6;
+        int textWidth = painter.fontMetrics().horizontalAdvance(numberStr) + 6;
 
         if (textWidth < result_size.width() / 2) {
             textWidth = result_size.width() / 2;
