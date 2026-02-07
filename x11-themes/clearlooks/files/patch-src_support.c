--- src/support.c.orig	Thu Jun  9 17:19:53 2005
+++ src/support.c	Thu Jun  9 17:20:15 2005
@@ -530,8 +530,8 @@
 void gtk_clist_get_header_index (GtkCList *clist, GtkWidget *button,
                                  gint *column_index, gint *columns)
 {
-	*columns = clist->columns;
 	int i;
+	*columns = clist->columns;
 	
 	for (i=0; i<*columns; i++)
 	{
