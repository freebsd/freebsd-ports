--- src/callbacks.c.orig	Fri Feb  4 08:17:01 2005
+++ src/callbacks.c	Fri Feb  4 08:17:38 2005
@@ -844,11 +844,12 @@
   GHashTable *Lhash = (GHashTable *) Adata;
   gboolean *Labort = (gboolean *)g_hash_table_lookup(Lhash, "gabort");
   GtkWidget *Lwindow = GTK_WIDGET(g_hash_table_lookup(Lhash, "window_burn"));
+  GtkWidget *Lconfirm;
   gint Lret;
 
   g_assert(Labort);
 
-  GtkWidget *Lconfirm = gtk_message_dialog_new(GTK_WINDOW(Lwindow),
+  Lconfirm = gtk_message_dialog_new(GTK_WINDOW(Lwindow),
                       GTK_DIALOG_MODAL, GTK_MESSAGE_QUESTION,
                       GTK_BUTTONS_YES_NO, _("Do you really want to abort operation ?"));
 
