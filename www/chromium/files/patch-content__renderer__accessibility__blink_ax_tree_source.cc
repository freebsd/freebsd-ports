--- content/renderer/accessibility/blink_ax_tree_source.cc.orig	2014-10-10 09:15:31 UTC
+++ content/renderer/accessibility/blink_ax_tree_source.cc
@@ -470,13 +470,15 @@
     dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X, scroll_offset.width());
     dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y, scroll_offset.height());
 
-    const gfx::Size& min_offset = document.minimumScrollOffset();
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MIN, min_offset.width());
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MIN, min_offset.height());
+    // Prefix {min|max}_offset with '_' to avoid collision with
+    // FreeBSD namespace
+    const gfx::Size& _min_offset = document.minimumScrollOffset();
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MIN, _min_offset.width());
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MIN, _min_offset.height());
 
-    const gfx::Size& max_offset = document.maximumScrollOffset();
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MAX, max_offset.width());
-    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MAX, max_offset.height());
+    const gfx::Size& _max_offset = document.maximumScrollOffset();
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_X_MAX, _max_offset.width());
+    dst->AddIntAttribute(ui::AX_ATTR_SCROLL_Y_MAX, _max_offset.height());
 
     if (node_to_frame_routing_id_map_ && !src.equals(GetRoot())) {
       WebLocalFrame* frame = document.frame();
