--- agent/seahorse-agent-io.c.orig	Fri Jan 28 15:52:18 2005
+++ agent/seahorse-agent-io.c	Fri Jan 28 15:54:19 2005
@@ -377,12 +377,18 @@
     gsize length;
     GError *err = NULL;
     gboolean ret = TRUE;
+    GIOStatus status;
 
     if (condition & G_IO_IN) {
         /* Read 1 line from the io channel, including newline character */
-        g_io_channel_read_line (source, &string, &length, NULL, &err);
+        status = g_io_channel_read_line (source, &string, &length, NULL, &err);
 
-        if (err != NULL) {
+	if (status == G_IO_STATUS_EOF) {
+	    free_conn (cn);
+	    ret = FALSE;
+	}
+
+	else if (err != NULL) {
             g_critical ("couldn't read from socket: %s", err->message);
             g_clear_error (&err);
             free_conn (cn);
@@ -398,7 +404,7 @@
             g_free (string);
     }
 
-    if (condition & G_IO_HUP) {
+    else if (condition & G_IO_HUP) {
         free_conn (cn);
         ret = FALSE;            /* removes watch */
     }
