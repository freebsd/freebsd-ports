--- src/HistoryDialog.vala.orig	2020-12-23 20:16:02 UTC
+++ src/HistoryDialog.vala
@@ -52,7 +52,7 @@ namespace PantheonCalculator {
 
         private void build_ui () {
             var content = get_content_area () as Gtk.Box;
-            get_action_area ().margin = 6;
+            content.margin = 6;
             main_grid = new Gtk.Grid ();
             main_grid.expand = true;
             main_grid.margin = 12;
