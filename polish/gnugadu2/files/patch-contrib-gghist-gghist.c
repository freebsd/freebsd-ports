--- contrib/gghist/gghist.c.orig	Fri Aug 20 14:17:29 2004
+++ contrib/gghist/gghist.c	Fri Jan 28 00:54:48 2005
@@ -244,6 +244,7 @@
 	GtkWidget *field_s;
 	GtkWidget *base_field;
 	GtkTextBuffer *buf;
+	int fd;
 
 	gtk_init(&argc, &argv);
 
@@ -257,7 +258,7 @@
 #ifdef GGADU_DEBUG
 	g_print("Trying to open a file..\n");
 #endif
-	int fd = open(argv[1], O_RDONLY);
+	fd = open(argv[1], O_RDONLY);
 
 	if (fd == -1) {
 		GtkWidget *dialog;
@@ -279,6 +280,7 @@
 	g_print("Getting lines count..\n");
 #endif
 	lines = lines_count(fd);
+	{
 	int list[lines + 2];
 
 
@@ -326,7 +328,6 @@
 	/* Add 'Base container' to window */
 	gtk_container_add(GTK_CONTAINER(window), base_field);
 
-
 	list[lines + 2] = fd;
 #ifdef GGADU_DEBUG
 	g_print("Reading offsets of lines..%d\n", lines);
@@ -344,6 +345,7 @@
 	else
 	    show_lines(0, display_pages, list);
 
+	}
 	gtk_widget_show_all(window);
 
 	gtk_main();
