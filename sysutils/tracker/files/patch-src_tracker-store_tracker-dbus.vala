--- src/tracker-store/tracker-dbus.vala.orig	2020-03-09 23:27:20 UTC
+++ src/tracker-store/tracker-dbus.vala
@@ -122,7 +122,7 @@ public class Tracker.DBus {
 		return true;
 	}
 
-	static void name_owner_changed_cb (DBusConnection connection, string sender_name, string object_path, string interface_name, string signal_name, Variant parameters) {
+	static void name_owner_changed_cb (DBusConnection connection, string? sender_name, string object_path, string interface_name, string signal_name, Variant parameters) {
 
 		unowned string name, old_owner, new_owner;
 		parameters.get ("(&s&s&s)", out name, out old_owner, out new_owner);
