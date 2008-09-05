--- src/gtk/main.c.orig	2008-08-16 17:39:31.000000000 +0200
+++ src/gtk/main.c	2008-08-16 17:40:29.000000000 +0200
@@ -255,6 +255,9 @@
 {
 	GtkWidget *window_nvclock;
 
+	gtk_set_locale ();
+	gtk_init (&argc, &argv);
+
 	/* Initialize nvclock. This must be done here instead of in the hardware backend
 	/  because of the configuration file which gets initialized by init_nvclock.
 	*/
@@ -269,9 +272,6 @@
 		return 0;
 	}
 
-	gtk_set_locale ();
-	gtk_init (&argc, &argv);
-
 	window_nvclock = create_window_main ();
 	gtk_widget_show (window_nvclock);
 
