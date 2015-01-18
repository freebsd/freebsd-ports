--- extras/makeweb.c.orig	2005-06-29 17:53:25 UTC
+++ extras/makeweb.c
@@ -48,6 +48,11 @@
 
 static char* argv0;
 
+static void
+usage( void )
+{
+    fprintf( stderr, "usage: %s [-d webdir]\n", argv0 );
+}
 
 static void
 check_room( int size, int len )
@@ -126,17 +131,27 @@ main( int argc, char** argv )
     struct passwd* pwd;
     char* username;
     char* homedir;
+    int opts;
     char dirname[5000];
     char linkname[5000];
     char linkbuf[5000];
     struct stat sb;
 
     argv0 = argv[0];
-    if ( argc != 1 )
+
+#ifndef TILDE_MAP_2
+    webdir = WEBDIR;
+#endif /* TILDE_MAP_2 */
+
+    if ( (opts = getopt(argc, argv, "d:h")) != -1 )
+    {
+	switch (opts)
 	{
-	(void) fprintf( stderr, "usage:  %s\n", argv0 );
-	exit( 1 );
+	    case 'd': webdir = strdup(optarg); break;
+	    case 'h':
+	    default: usage(); return 1; break;
 	}
+    }
 
     pwd = getpwuid( getuid() );
     if ( pwd == (struct passwd*) 0 )
@@ -162,8 +177,6 @@ main( int argc, char** argv )
 
 #else /* TILDE_MAP_2 */
 
-    /* Gather the pieces. */
-    webdir = WEBDIR;
 #ifdef TILDE_MAP_1
     prefix = TILDE_MAP_1;
 #else /* TILDE_MAP_1 */
