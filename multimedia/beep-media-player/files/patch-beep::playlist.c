--- beep/playlist.c.orig	Fri Nov 14 06:25:26 2003
+++ beep/playlist.c	Fri Nov 14 06:34:23 2003
@@ -607,6 +607,7 @@
 
 	while (*string)
 	{
+		GList *node;
 		temp = strchr(string, '\n');
 		if (temp)
 		{
@@ -633,7 +634,6 @@
 			}
 		}
 
-		GList *node;
 		node = g_list_nth(get_playlist(), pos);
 
 		entries += i;
@@ -2346,6 +2346,7 @@
 	guint64 node_idx;
 	gchar * from_real;
 	gboolean error;
+	db_node * node;
 
 	/* It's not really a waste creating both beforehand since we will certainly need the folder one at least once,
 	   and most probably the audio one too anyway */
@@ -2366,7 +2367,6 @@
 
 	current = gtk_tree_model_get_path(model, &parent_iter);
 	node_idx = dirbrowser_get_nodeidx_from_iter(model, &parent_iter, 0, &error);
-	db_node * node;
 	node = g_ptr_array_index(nodes, node_idx);
 	from_real = g_strconcat(node->path_real,"/",from,NULL);
 
@@ -2388,10 +2388,11 @@
 			{
 				while ((dirent = readdir(dir)) != NULL)
 				{
+					char * name_real;
 					// FIXME: Excludes hidden dirs too (do we want them anyway?)
 					if (dirent->d_name[0] == '.')
 						continue;
-					char * name_real = g_strdup(g_strconcat(from_real,"/",dirent->d_name,NULL));
+					name_real = g_strdup(g_strconcat(from_real,"/",dirent->d_name,NULL));
 					stat(name_real, &statbuf);
 
 					if ( S_ISDIR(statbuf.st_mode) ) {
@@ -2513,9 +2514,10 @@
 	char *buffer, **lines,  **frags;
 	struct stat stats;
 	guint i;
-
+	GdkPixbuf * buf;
+	
 	model = gtk_tree_store_new(2, GDK_TYPE_PIXBUF, G_TYPE_STRING);
-        GdkPixbuf * buf = gdk_pixbuf_new_from_inline(sizeof(harddisk_pixbuf),
+        buf = gdk_pixbuf_new_from_inline(sizeof(harddisk_pixbuf),
                                              harddisk_pixbuf,
                                              TRUE,
                                              NULL);
@@ -2803,13 +2805,16 @@
 	
 	PangoAttrList *attrs;
 	PangoAttribute     *attr;
+
+	GdkPixbuf * buf;
+
 	attrs = pango_attr_list_new ();
 	attr = pango_attr_weight_new (PANGO_WEIGHT_BOLD);
 	attr->start_index = 0;
 	attr->end_index   = -1;
 	pango_attr_list_insert (attrs, attr);
 	
-        GdkPixbuf * buf = gdk_pixbuf_new_from_inline(sizeof(harddisk_pixbuf),
+        buf = gdk_pixbuf_new_from_inline(sizeof(harddisk_pixbuf),
                                              harddisk_pixbuf,
                                              TRUE,
                                              NULL);
@@ -2863,9 +2868,10 @@
 		if ( S_ISDIR(statbuf.st_mode) ) {
 
 			db_node * node;
-			node = g_malloc0(sizeof(db_node));
 			char * dir = g_strdup(path_real);
 			char * name = g_strdup(path_real);
+			
+			node = g_malloc0(sizeof(db_node));
 			node->path_real = dir;
 
 			gtk_label_set_text(variable, g_strdup(g_strconcat("Choose a Name for:\n",name,NULL)));
@@ -2932,9 +2938,9 @@
 	                                            (model,
 	                                             &iter,
 							gtk_tree_path_to_string(paths->data))) {
+				db_node * node;
 				gtk_tree_store_remove (GTK_TREE_STORE(model), &iter);
 
-				db_node * node;
 				node = g_ptr_array_index(nodes, node_idx);
 				g_ptr_array_remove_index(nodes, node_idx);
 				ctr_array--;
@@ -3178,7 +3184,11 @@
       /* create window, etc */
 
       /* yes this is all messed up */
-      
+     	GSList * group;
+	GtkWidget * hbox_default_setting;
+	PangoAttrList *attrs;
+	PangoAttribute     *attr;
+			
 	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_title (GTK_WINDOW (window), "beep :: directory browser");
 	gtk_container_set_border_width(GTK_CONTAINER(window),
@@ -3195,8 +3205,6 @@
 
 	vbox = gtk_vbox_new (FALSE, 0);
 
-	PangoAttrList *attrs;
-	PangoAttribute     *attr;
 	attrs = pango_attr_list_new ();
 	attr = pango_attr_weight_new (PANGO_WEIGHT_BOLD);
 	attr->start_index = 0;
@@ -3235,8 +3243,6 @@
 	hbox = gtk_hbox_new (FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE, 0);
 
-	GSList * group;
-
 	rb_enq = gtk_radio_button_new(NULL);
 	group = gtk_radio_button_get_group(rb_enq);
 	rb_play = gtk_radio_button_new(group);
@@ -3257,7 +3263,6 @@
 
 	gtk_misc_set_alignment(GTK_MISC(label_rb), 0.0, 0.0);
 
-	gtk_label_set_attributes (GTK_LABEL(label_rb), attrs);
 
 	gtk_container_add(GTK_CONTAINER  (frame),vbox);
 	gtk_box_pack_start(GTK_BOX (vbox_main), frame,TRUE,TRUE,0);
@@ -3287,7 +3292,7 @@
 
 	hbox_lower = gtk_hbox_new(FALSE, 8);
 
-	GtkWidget * hbox_default_setting  = gtk_hbox_new(FALSE,8);
+	hbox_default_setting  = gtk_hbox_new(FALSE,8);
 
 	gtk_box_pack_start(GTK_BOX(hbox_default_setting), table_rb,FALSE,FALSE,0);
 	gtk_box_pack_start(GTK_BOX(hbox_default_setting), gtk_vseparator_new(), FALSE,FALSE,0);
