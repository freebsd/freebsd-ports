--- src/layout/Positioner.cpp.orig	2025-12-01 05:02:26 UTC
+++ src/layout/Positioner.cpp
@@ -96,7 +96,7 @@ void CPositioner::repositionNeeded(SP<IElement> elemen
     if (!element->impl->parent->impl->positionerData || element->impl->parent->impl->positionerData->baseBox.empty()) {
         if (force) {
             initElementIfNeeded(element);
-            position(element, CBox{Vector2D{}, element->preferredSize(Vector2D{}).value_or({})});
+            position(element, CBox{Vector2D{}, element->preferredSize(Vector2D{}).value_or(Vector2D{})});
         } else if (element->impl->window) // full reflow needed
             element->impl->window->scheduleReposition(element->impl->window->m_rootElement);
         return;
