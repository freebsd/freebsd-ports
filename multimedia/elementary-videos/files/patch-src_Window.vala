--- src/Window.vala.orig	2022-01-10 17:54:11 UTC
+++ src/Window.vala
@@ -67,9 +67,11 @@ public class Audience.Window : Gtk.ApplicationWindow {
         add_action_entries (ACTION_ENTRIES, this);
 
         var application_instance = (Gtk.Application) GLib.Application.get_default ();
-        foreach (var action in action_accelerators.get_keys ()) {
+        var iter = action_accelerators.map_iterator ();
+        while (iter.next ()) {
             application_instance.set_accels_for_action (
-                ACTION_PREFIX + action, action_accelerators[action].to_array ()
+                ACTION_PREFIX + iter.get_key (),
+                { iter.get_value () }
             );
         }
 
