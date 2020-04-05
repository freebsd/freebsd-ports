--- helperlibs/twitterapihelper/twitterapimicroblogwidget.cpp.orig	2020-02-05 11:49:13 UTC
+++ helperlibs/twitterapihelper/twitterapimicroblogwidget.cpp
@@ -67,7 +67,7 @@ QIcon addTextToIcon(const QIcon &icon, const QString &
     font.setBold(true);
     painter.setFont(font);
 
-    int textWidth = painter.fontMetrics().width(text);
+    int textWidth = painter.fontMetrics().horizontalAdvance(text);
     QRect rct(0 , 0 , textWidth , result_size.height() / 2);
 
     painter.setRenderHint(QPainter::Antialiasing);
