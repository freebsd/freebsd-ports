--- src/gtk/callbacks.c	Wed Aug 20 22:13:50 2003
+++ src/gtk/callbacks.c.patch	Wed Aug 20 23:14:35 2003
@@ -36,11 +36,12 @@
 {
     va_list arg;
     char* message;
+    GtkWidget *dialog;
+
     va_start(arg, format);
 
     message = g_strdup_vprintf(format, arg);
     
-    GtkWidget *dialog;
     switch(code)
     {
 	case ERROR:
@@ -108,6 +109,7 @@
 {
     GtkWidget *label;
     Timeout *timeout;
+    gint result;
     timeout = g_malloc(sizeof(Timeout));
 
     timeout->dialog = GTK_DIALOG(gtk_dialog_new_with_buttons("Testing the new speeds", 
@@ -126,7 +128,7 @@
     /* Create the real timeout */
     timeout->timeout_id = g_timeout_add(1000, timeout_callback, timeout);
 
-    gint result = gtk_dialog_run(GTK_DIALOG(timeout->dialog));
+    result = gtk_dialog_run(GTK_DIALOG(timeout->dialog));
 
     /* Stop the timer because we got an answer back */
     g_source_remove(timeout->timeout_id);
