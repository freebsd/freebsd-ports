--- src/window/WaylandPopup.cpp.orig	2025-11-12 08:33:32 UTC
+++ src/window/WaylandPopup.cpp
@@ -59,7 +59,7 @@ void CWaylandPopup::open() {
     m_wlPopupState.xdgPositioner->sendSetAnchorRect(m_creationData.pos.x, m_creationData.pos.y, 1, 1);
     m_wlPopupState.xdgPositioner->sendSetAnchor(XDG_POSITIONER_ANCHOR_TOP_LEFT);
     m_wlPopupState.xdgPositioner->sendSetGravity(XDG_POSITIONER_GRAVITY_BOTTOM_RIGHT);
-    m_wlPopupState.xdgPositioner->sendSetSize(m_creationData.preferredSize.value_or({200, 200}).x, m_creationData.preferredSize.value_or({200, 200}).y);
+    m_wlPopupState.xdgPositioner->sendSetSize(m_creationData.preferredSize.value_or(Vector2D{200, 200}).x, m_creationData.preferredSize.value_or(Vector2D{200, 200}).y);
     m_wlPopupState.xdgPositioner->sendSetConstraintAdjustment(
         (xdgPositionerConstraintAdjustment)(XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_SLIDE_Y | XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_SLIDE_X));
 
