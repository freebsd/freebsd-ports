--- src/font-manager/FontList.vala.orig	2025-03-08 00:43:35 UTC
+++ src/font-manager/FontList.vala
@@ -669,7 +669,8 @@ namespace FontManager {
             widget_set_name(drag_count, "FontManagerListDragCount");
             drag_icon.add_overlay(drag_count);
             drag_count.set_label(selected_items.length.to_string());
-            var gtk_drag_icon = (Gtk.DragIcon) Gtk.DragIcon.get_for_drag(drag);
+            // var gtk_drag_icon = (Gtk.DragIcon) Gtk.DragIcon.get_for_drag(drag);
+            var gtk_drag_icon = new Gtk.DragIcon.get_for_drag(drag);
             gtk_drag_icon.set_child(drag_icon);
             return;
         }
