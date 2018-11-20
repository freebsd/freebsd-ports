--- gtv.c.orig	2001-04-16 19:08:54 UTC
+++ gtv.c
@@ -963,6 +963,7 @@ int main( int argc, char* argv[] )
     memset( &filename_buffer, 0, sizeof( gchar ) * FILENAME_BUFFER_SIZE );
     gtk_set_locale();
     gtk_init( &argc, &argv );
+    gtk_set_locale ();
 
     window = create_gtv_window( );
     gtk_drag_dest_set(window, GTK_DEST_DEFAULT_ALL, drop_types, 1, GDK_ACTION_COPY);
