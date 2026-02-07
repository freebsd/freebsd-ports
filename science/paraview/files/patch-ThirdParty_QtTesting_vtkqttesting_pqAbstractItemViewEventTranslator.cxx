--- ThirdParty/QtTesting/vtkqttesting/pqAbstractItemViewEventTranslator.cxx.orig	2025-09-25 09:24:50 UTC
+++ ThirdParty/QtTesting/vtkqttesting/pqAbstractItemViewEventTranslator.cxx
@@ -90,8 +90,8 @@ bool pqAbstractItemViewEventTranslator::translateEvent
 
       QString info = QString("%1,%2,%3,%4,%5,%6")
                        .arg(mouseEvent->button())
-                       .arg(mouseEvent->buttons())
-                       .arg(mouseEvent->modifiers())
+                       .arg(static_cast<int>(mouseEvent->buttons()))
+                       .arg(static_cast<int>(mouseEvent->modifiers()))
                        .arg(relPt.x())
                        .arg(relPt.y())
                        .arg(idxStr);
