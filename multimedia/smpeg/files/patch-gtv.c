--- gtv.c.orig	Sun Mar 26 00:18:54 2000
+++ gtv.c	Sun Mar 26 00:19:17 2000
@@ -726,6 +726,7 @@
     memset( &info, 0, sizeof( info ) );
     memset( &filename_buffer, 0, sizeof( gchar ) * FILENAME_BUFFER_SIZE );
     gtk_init( &argc, &argv );
+    gtk_set_locale ();
 
     window = create_gtv_window( );
     gtk_signal_connect( GTK_OBJECT( window ), "destroy",
