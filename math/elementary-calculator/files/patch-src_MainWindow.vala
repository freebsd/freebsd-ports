Replace missing icons (Adwaita)

--- src/MainWindow.vala.orig	2022-05-10 20:12:35 UTC
+++ src/MainWindow.vala
@@ -78,7 +78,7 @@ public class PantheonCalculator.MainWindow : Gtk.Appli
         history = new List<History?> ();
         position = 0;
         button_extended = new Gtk.ToggleButton () {
-            icon_name = "pane-hide-symbolic",
+            icon_name = "pan-end-symbolic",
             tooltip_text = _("Show extended functionality")
         };
         button_extended.toggled.connect (toggle_grid);
@@ -731,12 +731,12 @@ public class PantheonCalculator.MainWindow : Gtk.Appli
         position = entry.get_position ();
         if (button.get_active ()) {
             /* Show extended functionality */
-            button.icon_name = "pane-show-symbolic";
+            button.icon_name = "pan-start-symbolic";
             button.tooltip_text = _("Hide extended functionality");
             extended_revealer.reveal_child = true;
         } else {
             /* Hide extended functionality */
-            button.icon_name = "pane-hide-symbolic";
+            button.icon_name = "pan-end-symbolic";
             button.tooltip_text = _("Show extended functionality");
             extended_revealer.reveal_child = false;
         }
