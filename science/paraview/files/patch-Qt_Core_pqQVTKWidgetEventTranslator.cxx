--- Qt/Core/pqQVTKWidgetEventTranslator.cxx.orig	2025-09-25 09:24:50 UTC
+++ Qt/Core/pqQVTKWidgetEventTranslator.cxx
@@ -90,8 +90,8 @@ bool pqQVTKWidgetEventTranslator::translateEvent(
               .arg(normalized_x)
               .arg(normalized_y)
               .arg(mouseEvent->button())
-              .arg(mouseEvent->buttons())
-              .arg(mouseEvent->modifiers()));
+              .arg(static_cast<int>(mouseEvent->buttons()))
+              .arg(static_cast<int>(mouseEvent->modifiers())));
         }
         return true;
         break;
@@ -118,15 +118,15 @@ bool pqQVTKWidgetEventTranslator::translateEvent(
               .arg(normalized_x)
               .arg(normalized_y)
               .arg(mouseEvent->button())
-              .arg(mouseEvent->buttons())
-              .arg(mouseEvent->modifiers()));
+              .arg(static_cast<int>(mouseEvent->buttons()))
+              .arg(static_cast<int>(mouseEvent->modifiers())));
           Q_EMIT recordEvent(widget, "mouseRelease",
             QString("(%1,%2,%3,%4,%5)")
               .arg(normalized_x)
               .arg(normalized_y)
               .arg(mouseEvent->button())
-              .arg(mouseEvent->buttons())
-              .arg(mouseEvent->modifiers()));
+              .arg(static_cast<int>(mouseEvent->buttons()))
+              .arg(static_cast<int>(mouseEvent->modifiers())));
         }
         return true;
         break;
