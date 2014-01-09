--- ./src/mainwindow.cpp.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/mainwindow.cpp	2014-01-08 10:20:11.000000000 +0100
@@ -299,6 +299,8 @@
   gchar *workgroup = NULL, *command = NULL, *comment = NULL, *comment2 = NULL;
   gint h;
 
+  if(!parent_tree)
+      return FALSE;
 
   if (GTK_TREE(parent_tree)->children) 
     gtk_tree_remove_items(GTK_TREE(parent_tree), 
@@ -349,11 +351,15 @@
 
     while (glist->next) {
       //---get the string width in pixels----------------------------------
-      h = gdk_string_width(style->font, "DDDDDDDDDDDDDDDDD") - 
-	gdk_string_width(style->font, (gchar *)glist->next->data);
-      h /= gdk_string_width(style->font, "D");
+	if(style) {
+	    h = gdk_string_width(style->font, "DDDDDDDDDDDDDDDDD") - 
+		gdk_string_width(style->font, (gchar *)glist->next->data);
+	    h /= gdk_string_width(style->font, "D");
+		comment = g_strnfill(h, 0x20);
+	} else {
+		comment = NULL;
+	}
       
-      comment = g_strnfill(h, 0x20);
       comment2 = g_strescape(g_strconcat((gchar *)glist->next->data, comment, 
 					 (gchar *)glist2->next->data, NULL));
       g_free(comment);
@@ -414,6 +420,9 @@
   gchar *ShareName = new gchar[100];
   gint h;
 
+  if(!parent_tree)
+      return FALSE;
+
   /* Get the text on this treeitem into "workgroup" */
   item = GTK_TREE(parent_tree)->tree_owner;
   server = g_strdup_printf("%s", gtk_tree_item_get_text(item));
@@ -478,9 +487,11 @@
     while (glist->next) {
       if (g_strncasecmp((gchar *)glist->next->data, "Error", 5)) {
 	g_strdup_printf(ShareName,"%s", (gchar *)glist->next->data);
-	h = gdk_string_width(style->font, "DDDDDDDDDDDDDDDDDDD") - 
-	  gdk_string_width(style->font, (gchar *)glist->next->data);
-	h /= gdk_string_width(style->font, " ");
+	if (style) {
+	    h = gdk_string_width(style->font, "DDDDDDDDDDDDDDDDDDD") - 
+		gdk_string_width(style->font, (gchar *)glist->next->data);
+	    h /= gdk_string_width(style->font, " ");
+	}
 	comment = g_strnfill(h, 0x20);
 	comment2 = g_strconcat((gchar *)glist->next->data, comment, 
 			       (gchar *)glist3->next->data, NULL);
