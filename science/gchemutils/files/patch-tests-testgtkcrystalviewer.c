--- tests/testgtkcrystalviewer.c.orig	Mon Nov 11 19:50:18 2002
+++ tests/testgtkcrystalviewer.c	Tue Mar 18 11:25:55 2003
@@ -8,6 +8,8 @@
 {
 	GtkWidget *window;
 	GtkWidget *viewer;
+	const char* filename;
+	xmlDocPtr xml;
 	gtk_init (&argc, &argv);
 
 	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
@@ -16,10 +18,9 @@
 		 GTK_SIGNAL_FUNC(gtk_main_quit),
 		 NULL);
 
-	const char* filename;
 	if (argc >= 2) filename = argv[1];
 		else filename = "nickel.gcrystal";
-	xmlDocPtr xml = xmlParseFile(filename);
+	xml = xmlParseFile(filename);
 	
 	viewer = gtk_crystal_viewer_new(xml->children);
 	gtk_container_add(GTK_CONTAINER(window), viewer);
