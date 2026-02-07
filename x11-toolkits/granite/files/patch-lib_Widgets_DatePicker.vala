--- lib/Widgets/DatePicker.vala.orig	2018-12-17 13:02:11 UTC
+++ lib/Widgets/DatePicker.vala
@@ -85,7 +85,7 @@ namespace Granite.Widgets {
             // Entry properties
             can_focus = false;
             editable = false; // user can't edit the entry directly
-            secondary_icon_gicon = new ThemedIcon.with_default_fallbacks ("office-calendar-symbolic");
+            secondary_icon_gicon = new ThemedIcon.with_default_fallbacks ("x-office-calendar-symbolic");
 
             dropdown.add_events (Gdk.EventMask.FOCUS_CHANGE_MASK);
             dropdown.add (calendar);
