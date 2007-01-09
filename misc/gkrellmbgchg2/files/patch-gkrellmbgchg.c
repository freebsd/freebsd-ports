--- gkrellmbgchg.c.orig	Thu Jun 29 05:19:13 2006
+++ gkrellmbgchg.c	Sat Jan  6 02:06:10 2007
@@ -117,7 +117,9 @@
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
@@ -128,7 +130,6 @@
 
 #if !defined(WIN32)
 	/* don't load if no force and not modified */
-	struct stat buf;
 	if( stat( tmp, &buf ) == -1 ) {
 		/* something went wrong, we just don't care what for now */
 		GKBG_debug("stat: error on `%s'", tmp);
