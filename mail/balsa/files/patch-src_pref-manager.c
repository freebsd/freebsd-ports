--- src/pref-manager.c.orig	Sat Apr  2 03:54:40 2005
+++ src/pref-manager.c	Sat Apr  2 03:55:05 2005
@@ -2457,13 +2457,14 @@ moving_messages_group(GtkWidget * page)
 {
     GtkWidget *group;
     GtkWidget *label;
+    GtkWidget *table;
 
     group = pm_group_new(_("Message Window"));
 
     label = gtk_label_new(_("Action after moving/trashing a message"));
     gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
 
-    GtkWidget *table = create_table(4, 2, page);
+    table = create_table(4, 2, page);
     gtk_table_attach(GTK_TABLE(table), label, 0, 1, 3, 4,
 		     (GtkAttachOptions) (GTK_FILL),
 		     (GtkAttachOptions) (0), 0, 0);
