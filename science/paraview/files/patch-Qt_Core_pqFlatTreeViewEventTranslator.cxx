--- Qt/Core/pqFlatTreeViewEventTranslator.cxx.orig	2025-09-25 09:24:50 UTC
+++ Qt/Core/pqFlatTreeViewEventTranslator.cxx
@@ -73,8 +73,8 @@ bool pqFlatTreeViewEventTranslator::translateEvent(QOb
 
       QString info = QString("%1,%2,%3,%4,%5,%6")
                        .arg(mouseEvent->button())
-                       .arg(mouseEvent->buttons())
-                       .arg(mouseEvent->modifiers())
+                       .arg(static_cast<int>(mouseEvent->buttons()))
+                       .arg(static_cast<int>(mouseEvent->modifiers()))
                        .arg(relPt.x())
                        .arg(relPt.y())
                        .arg(idxStr);
