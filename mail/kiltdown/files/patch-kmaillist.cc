--- kiltdown/kmaillist.cc.orig	Mon May 14 05:25:23 2001
+++ kiltdown/kmaillist.cc	Mon Sep  9 11:53:44 2002
@@ -12,6 +12,7 @@
 
 #include <qdrawutil.h>
 #include <qpainter.h>
+#include <qstyle.h>
 #include <stdio.h>
 #include <string.h>
 
@@ -616,6 +617,7 @@
     int w = this->drawableWidth() - PAD;
     int colwidth, colleft = PAD;
     int x;
+    QRect *rect;
 
     /**
      * First thing we need to do is figure out how much space the fixed width
@@ -646,8 +648,12 @@
         if (!_backgroundBrush) _backgroundBrush = new QBrush(cg.color(QColorGroup::Button));
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
          * Next, draw the text or the image.
@@ -1717,15 +1723,15 @@
                         && (x < (w + PAD + 1))
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
             break;
@@ -2471,7 +2477,7 @@
     /**
      * Finally, reset the cursor, mode, and repaint ourself.
      */
-    this->setCursor(ArrowCursor);
+    this->setCursor(arrowCursor);
     this->mouseMode = MMNormal;
     emitColumnsChanged();
     this->forceUpdate();
