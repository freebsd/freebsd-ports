--- bogofilter-0.8.0/config.c	Thu Oct 31 06:23:32 2002
+++ bogofilter-0.8.0.1/config.c	Mon Nov 11 02:06:36 2002
@@ -21,6 +21,7 @@
 #include "wordlists.h"
 #include "xmalloc.h"
 #include "xstrdup.h"
+#include "find_home.h"
 
 #ifndef	DEBUG_CONFIG
 #define DEBUG_CONFIG(level)	(verbose > level)
@@ -150,7 +151,7 @@
 
     if ( *filename == '~' )
     {
-	char *home = getenv( "HOME" );
+	char *home = find_home(TRUE);
 	if ( home == NULL )
 	{
 	    fprintf( stderr, "Can't find $HOME.\n" );
