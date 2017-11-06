Replace missing icons (Adwaita)

--- src/MainWindow.vala.orig	2016-08-10 05:29:30 UTC
+++ src/MainWindow.vala
@@ -73,8 +73,8 @@ namespace PantheonCalculator {
             headerbar.set_title (_("Calculator"));
             set_titlebar (headerbar); 
 
-            extended_img_1 = new Gtk.Image.from_icon_name ("pane-hide-symbolic", Gtk.IconSize.MENU);
-            extended_img_2 = new Gtk.Image.from_icon_name ("pane-show-symbolic", Gtk.IconSize.MENU);
+            extended_img_1 = new Gtk.Image.from_icon_name ("pan-end-symbolic", Gtk.IconSize.MENU);
+            extended_img_2 = new Gtk.Image.from_icon_name ("pan-start-symbolic", Gtk.IconSize.MENU);
 
             button_extended = new Gtk.ToggleButton ();
             button_extended.image = extended_img_1;
