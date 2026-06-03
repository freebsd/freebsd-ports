--- src/font-manager/Collections.vala.orig	2025-03-08 00:43:35 UTC
+++ src/font-manager/Collections.vala
@@ -540,7 +540,8 @@ namespace FontManager {
             var row = ((CollectionListRow) source.widget);
             var drag_icon = new Gtk.Label(row.item_label.label);
             drag_icon.add_css_class("FontManagerListRowDrag");
-            var gtk_drag_icon = (Gtk.DragIcon) Gtk.DragIcon.get_for_drag(drag);
+            // var gtk_drag_icon = (Gtk.DragIcon) Gtk.DragIcon.get_for_drag(drag);
+            var gtk_drag_icon = new Gtk.DragIcon.get_for_drag(drag);
             gtk_drag_icon.set_child(drag_icon);
             return;
         }
