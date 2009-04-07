--- kiltdown/kmaillist.cc	2001-05-13 23:25:23.000000000 -0400
+++ kiltdown/kmaillist.cc	2008-05-21 23:23:49.000000000 -0400
@@ -13,4 +13,5 @@
 #include <qdrawutil.h>
 #include <qpainter.h>
+#include <qstyle.h>
 #include <stdio.h>
 #include <string.h>
@@ -617,4 +618,5 @@
     int colwidth, colleft = PAD;
     int x;
+    QRect *rect;
 
     /**
@@ -647,6 +649,10 @@
         if (!_backgroundBrush) return;
 
-        style().drawBevelButton(&painter, colleft, 0, colwidth, getRowHeight(), 
-                                cg, headers[x].pressed, _backgroundBrush);
+	rect = new QRect( colleft, 0, colwidth, getRowHeight() );
+        style().drawPrimitive( QStyle::PE_ButtonBevel, &painter, *rect, cg,
+				headers[x].pressed ?
+					QStyle::Style_Default :
+					QStyle::Style_Sunken );
+	delete rect;
 
         /**
@@ -1252,5 +1258,5 @@
 ERRCODE KMailList::getSelectedRows
 (
-    LinkList<unsigned int> &list
+    LinkList<void *> &list
 )
 {
@@ -1718,13 +1724,13 @@
                         && (headers[z - 1].type != CW_FIXED)) {
 
-                        this->setCursor(SplitVCursor);
+                        this->setCursor(splitVCursor);
                         break;
                     } else {
-                        this->setCursor(ArrowCursor);
+                        this->setCursor(arrowCursor);
                         w += headers[z].widthCache;
                     }
                 }
             } else {
-                this->setCursor(ArrowCursor);
+                this->setCursor(arrowCursor);
             }
             }
@@ -1984,5 +1990,5 @@
 KMailListItem *KMailList::nextItem
 (
-    unsigned int itemData
+    void * itemData
 )
 {
@@ -2301,5 +2307,5 @@
 KMailListItem *KMailList::previousItem
 (
-    unsigned int itemData
+    void * itemData
 )
 {
@@ -2335,5 +2341,5 @@
 (
     int count,
-    unsigned int *itemDataArray
+    void **itemDataArray
 )
 {
@@ -2472,5 +2478,5 @@
      * Finally, reset the cursor, mode, and repaint ourself.
      */
-    this->setCursor(ArrowCursor);
+    this->setCursor(arrowCursor);
     this->mouseMode = MMNormal;
     emitColumnsChanged();
@@ -2571,5 +2577,5 @@
 ERRCODE KMailList::selectRowFromItemData
 (
-    unsigned int itemData
+    void * itemData
 )
 {
@@ -2779,5 +2785,5 @@
 ERRCODE KMailList::updateRowFromItemData
 (
-    unsigned int itemData,
+    void * itemData,
     KMailListItem *newRow
 )
