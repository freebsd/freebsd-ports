--- src/bmpx.c.orig	2009-09-23 22:02:33.000000000 +0300
+++ src/bmpx.c	2009-09-23 22:03:54.000000000 +0300
@@ -41,7 +41,7 @@
 static int connected = 0;
 static char *unknown = "unknown";
 
-void fail(GError *error);
+void fail(GError *error, struct information *);
 
 void update_bmpx()
 {
@@ -57,15 +57,15 @@
 		bus = dbus_g_bus_get(DBUS_BUS_SESSION, &error);
 		if (bus == NULL) {
 			ERR("BMPx error 1: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
 		remote_object = dbus_g_proxy_new_for_name(bus, BMP_DBUS_SERVICE,
-				BMP_DBUS_PATH, BMP_DBUS_INTERFACE);
+				BMP_DBUS_PATH__BMP, BMP_DBUS_INTERFACE__BMP);
 		if (!remote_object) {
 			ERR("BMPx error 2: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
@@ -77,7 +77,7 @@
 					G_TYPE_INVALID, G_TYPE_INT, &current_track, G_TYPE_INVALID)) {
 		} else {
 			ERR("BMPx error 3: %s\n", error->message);
-			fail(error);
+			fail(error, current_info);
 			return;
 		}
 
@@ -111,17 +111,17 @@
 				g_value_get_string(g_hash_table_lookup(metadata, "location"));
 		} else {
 			ERR("BMPx error 4: %s\n", error->message);
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
