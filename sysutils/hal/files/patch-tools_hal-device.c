--- tools/hal-device.c.orig	Sat Oct  7 18:15:26 2006
+++ tools/hal-device.c	Sat Oct  7 18:15:34 2006
@@ -155,7 +155,7 @@ int main(int argc, char **argv)
 
 	libhal_ctx_shutdown(hal_ctx, &error);
 	libhal_ctx_free(hal_ctx);
-	dbus_connection_disconnect(conn);
+	dbus_connection_close(conn);
 	dbus_connection_unref(conn);
 	dbus_error_free(&error);
 
