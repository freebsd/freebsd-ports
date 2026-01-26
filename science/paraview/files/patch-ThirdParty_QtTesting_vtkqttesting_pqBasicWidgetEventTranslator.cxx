--- ThirdParty/QtTesting/vtkqttesting/pqBasicWidgetEventTranslator.cxx.orig	2025-09-25 09:24:50 UTC
+++ ThirdParty/QtTesting/vtkqttesting/pqBasicWidgetEventTranslator.cxx
@@ -53,8 +53,8 @@ bool pqBasicWidgetEventTranslator::translateEvent(
 #endif
         QString info = QString("%1,%2,%3,%4,%5")
                          .arg(mouseEvent->button())
-                         .arg(mouseEvent->buttons())
-                         .arg(mouseEvent->modifiers())
+                         .arg(static_cast<int>(mouseEvent->buttons()))
+                         .arg(static_cast<int>(mouseEvent->modifiers()))
                          .arg(pos.x())
                          .arg(pos.y());
 
