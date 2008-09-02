--- src/preliminaries.c.orig	2008-09-03 00:54:16.000000000 -0500
+++ src/preliminaries.c	2008-09-03 00:54:38.000000000 -0500
@@ -276,7 +276,7 @@
 PL_init_mem();
 
 if( PLS.debug ) {
-        fprintf( PLS.diagfp, "Version: pl %s\n", PLVERSION );
+        fprintf( PLS.diagfp, "Version: ploticus %s\n", PLVERSION );
         if( PLS.cgiargs != NULL ) fprintf( PLS.diagfp, "operating in CGI mode\n" );
         Epcodedebug( 1, PLS.diagfp ); /* tell pcode.c to output diagnostics too */
         }
