--- ssh/seahorse-ssh-operation.c.orig	2008-07-21 18:15:51.000000000 -0400
+++ ssh/seahorse-ssh-operation.c	2008-07-22 22:49:51.000000000 -0400
@@ -280,11 +280,14 @@ askpass_handler (GIOChannel *source, GIO
     const gchar *result = NULL;
 
     if (condition & G_IO_IN) {
+	GIOStatus status;
         
         /* Read 1 line from the io channel, including newline character */
-        g_io_channel_read_line (source, &string, &length, NULL, &err);
+        status = g_io_channel_read_line (source, &string, &length, NULL, &err);
 
-        if (err != NULL) {
+	if (status == G_IO_STATUS_EOF) {
+		ret = FALSE;
+	} else if (err != NULL) {
             g_critical ("couldn't read from seahorse-ssh-askpass: %s", err->message);
             g_clear_error (&err);
             ret = FALSE;
