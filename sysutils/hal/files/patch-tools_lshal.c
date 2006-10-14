--- tools/lshal.c.orig	Sat Oct  7 18:14:43 2006
+++ tools/lshal.c	Sat Oct  7 18:14:59 2006
@@ -705,7 +705,7 @@ main (int argc, char *argv[])
 	libhal_ctx_shutdown (hal_ctx, &error);
 	libhal_ctx_free (hal_ctx);
 
-	dbus_connection_disconnect (conn);
+	dbus_connection_close (conn);
 	dbus_connection_unref (conn);
 
 	if (show_device)
