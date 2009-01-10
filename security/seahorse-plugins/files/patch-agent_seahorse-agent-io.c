--- agent/seahorse-agent-io.c.orig	Sun Aug 28 15:52:02 2005
+++ agent/seahorse-agent-io.c	Fri Oct  7 21:51:25 2005
@@ -412,12 +412,18 @@ io_handler (GIOChannel *source, GIOCondi
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
@@ -434,7 +440,7 @@ io_handler (GIOChannel *source, GIOCondi
             g_free (string);
     }
 
-    if (cn && condition & G_IO_HUP) {
+    else if (cn && condition & G_IO_HUP) {
         free_conn (cn);
         ret = FALSE;            /* removes watch */
     }
