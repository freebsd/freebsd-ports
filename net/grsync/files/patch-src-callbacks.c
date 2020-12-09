Avoid using nested functions to fix build on LLVM

--- src/callbacks.c.orig	2020-11-23 13:52:42 UTC
+++ src/callbacks.c
@@ -40,12 +40,13 @@ GtkTreeModelFilter *filter = NULL;
 gboolean more = FALSE, first = TRUE;
 
 
-void dialog_set_labels_selectable(GtkWidget *dialog) {
-	void _set_label_selectable(gpointer data, gpointer user_data) {
-		GtkWidget *widget = GTK_WIDGET(data);
-		if (GTK_IS_LABEL(widget)) gtk_label_set_selectable(GTK_LABEL(widget), TRUE);
-	}
+void _set_label_selectable(gpointer data, gpointer user_data) {
+	GtkWidget *widget = GTK_WIDGET(data);
+	if (GTK_IS_LABEL(widget)) gtk_label_set_selectable(GTK_LABEL(widget), TRUE);
+}
 
+
+void dialog_set_labels_selectable(GtkWidget *dialog) {
 	GtkWidget *area = gtk_message_dialog_get_message_area(GTK_MESSAGE_DIALOG(dialog));
 	GtkContainer *box = (GtkContainer *) area;
 	GList *children = gtk_container_get_children(box);
