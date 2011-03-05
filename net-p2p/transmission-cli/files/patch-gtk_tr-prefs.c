--- gtk/tr-prefs.c.orig	2011-02-28 17:16:03.000000000 -0600
+++ gtk/tr-prefs.c	2011-02-28 17:16:10.000000000 -0600
@@ -730,7 +730,7 @@
 onLaunchClutchCB( GtkButton * w UNUSED, gpointer data UNUSED )
 {
     const int port = gtr_pref_int_get( TR_PREFS_KEY_RPC_PORT );
-    char * uri = g_strdup_printf( "http://localhost:%d/transmission/web", port );
+    char * uri = g_strdup_printf( "http://localhost:%d/transmission/web/", port );
 
     gtr_open_uri( uri );
     g_free( uri );
