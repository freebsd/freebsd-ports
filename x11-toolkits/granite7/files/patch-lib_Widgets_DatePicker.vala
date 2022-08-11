--- lib/Widgets/DatePicker.vala.orig	2022-04-30 18:14:07 UTC
+++ lib/Widgets/DatePicker.vala
@@ -50,7 +50,7 @@ public class Granite.DatePicker : Gtk.Entry, Gtk.Build
 
         // Entry properties
         editable = false; // user can't edit the entry directly
-        primary_icon_gicon = new ThemedIcon.with_default_fallbacks ("office-calendar-symbolic");
+        primary_icon_gicon = new ThemedIcon.with_default_fallbacks ("x-office-calendar-symbolic");
         secondary_icon_gicon = new ThemedIcon.with_default_fallbacks ("pan-down-symbolic");
 
         add_css_class ("date-picker");
