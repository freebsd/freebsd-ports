--- gkrellmbgchg.c.orig	Wed Apr 26 17:41:54 2006
+++ gkrellmbgchg.c	Wed Apr 26 17:54:17 2006
@@ -114,7 +114,9 @@
 {
 	FILE *file;
 	gchar *tmp;
-
+#if !defined(WIN32)
+	struct stat buf;
+#endif
 	if( filename ) {
 		if( !strncmp( filename, "~/", MIN(2, strlen(filename)) ) )
 			tmp = g_strdup_printf( "%s/%s", g_get_home_dir(), filename+2 );
@@ -125,7 +127,6 @@
 
 #if !defined(WIN32)
 	/* don't load if no force and not modified */
-	struct stat buf;
 	if( stat( tmp, &buf ) == -1 ) {
 		/* something went wrong, we just don't care what for now */
 		GKBG_debug("stat: error on `%s'", tmp);
@@ -223,6 +224,9 @@
 	gint num=1;
 	FILE *idb_file;
 	struct idb_entry *idb_e;
+#if !defined(WIN32)
+	struct stat buf;
+#endif
 
 	if((idb_file = open_imagelist( bgmon.idb, force )) == NULL) return 1;
 
@@ -261,7 +265,6 @@
 #if !defined(WIN32)
 		/* ignore the file if we stat returns -1 (error) and the user wants
 		 * us to */
-		struct stat buf;
 		if( bgmon.ignore && (stat( tmp, &buf ) == -1) ) {
 			GKBG_debug( "ignoring `%s'", tmp );
 		} else {
