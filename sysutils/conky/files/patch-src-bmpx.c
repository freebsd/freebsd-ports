--- src/bmpx.c.orig
+++ src/bmpx.c
@@ -42,7 +42,7 @@
 static int connected = 0;
 static char *unknown = "unknown";
 
-void fail(GError *error);
+void fail(GError *error, struct information *);
 
 void update_bmpx()
 {
@@ -58,15 +58,15 @@
 		bus = dbus_g_bus_get(DBUS_BUS_SESSION, &error);
 		if (bus == NULL) {
 			NORM_ERR("BMPx error 1: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
 		remote_object = dbus_g_proxy_new_for_name(bus, BMP_DBUS_SERVICE,
-				BMP_DBUS_PATH, BMP_DBUS_INTERFACE);
+				BMP_DBUS_PATH__BMP, BMP_DBUS_INTERFACE__BMP);
 		if (!remote_object) {
 			NORM_ERR("BMPx error 2: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
@@ -78,7 +78,7 @@
 					G_TYPE_INVALID, G_TYPE_INT, &current_track, G_TYPE_INVALID)) {
 		} else {
 			NORM_ERR("BMPx error 3: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
@@ -112,17 +112,17 @@
 				g_value_get_string(g_hash_table_lookup(metadata, "location"));
 		} else {
 			NORM_ERR("BMPx error 4: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
 		g_hash_table_destroy(metadata);
 	} else {
-		fail(error);
+		fail(error, current_info);
 	}
 }
 
-void fail(GError *error)
+void fail(GError *error, struct information *current_info)
 {
 	if (error) {
 		g_error_free(error);
