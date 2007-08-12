--- window2.c.orig	2007-08-12 18:52:11.000000000 +0200
+++ window2.c	2007-08-12 18:52:53.000000000 +0200
@@ -223,7 +223,7 @@
 	GtkWidget * x, *apply_button,*add_new_button;
 	gchar * c, *c2;
 	int i;
-	int select = (int)data;
+	long select = (long)data;
 	gchar * clist_item[3];
 	//	printf("point2 data = %d\n",select);
 	apply_button = (GtkWidget*)gtk_object_get_data(GTK_OBJECT(window2),"button2");
