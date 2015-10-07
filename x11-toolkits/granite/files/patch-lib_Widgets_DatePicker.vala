--- lib/Widgets/DatePicker.vala.orig	2015-08-30 10:13:06 UTC
+++ lib/Widgets/DatePicker.vala
@@ -77,7 +77,7 @@ namespace Granite.Widgets {
             // Entry properties
             can_focus = false;
             editable = false; // user can't edit the entry directly
-            secondary_icon_gicon = new ThemedIcon.with_default_fallbacks ("office-calendar-symbolic");
+            secondary_icon_gicon = new ThemedIcon.with_default_fallbacks ("x-office-calendar-symbolic");
 
             dropdown.add_events (EventMask.FOCUS_CHANGE_MASK);
             dropdown.add (calendar);
