--- ./lcksum.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./lcksum.c	2014-06-29 12:15:04.247544144 +0200
@@ -434,7 +434,7 @@
 		/* Check to see if checksum is listed in transcript */
 		if ( strcmp( targv[ 7 ], "-" ) != 0) {
 		    /* use mtime from server */
-		    fprintf( ufs, "%s %-37s %4s %5s %5s %9ld "
+		    fprintf( ufs, "%s %-37s %4s %5s %5s %9" PRItimet "d "
 			    "%7" PRIofft "d %s\n",
 			targv[ 0 ], targv[ 1 ], targv[ 2 ], targv[ 3 ],
 			targv[ 4 ], st.st_mtime, st.st_size, lcksum );
@@ -457,6 +457,12 @@
 	}
 	free( line );
     }
+    if ( fclose( f ) != 0 ) {
+	fprintf( stderr, "%s: fclose failed: %s\n", path, strerror( errno ));
+	cleanup( updatetran, upath );
+	exit( 2 );
+    }
+
     if ( showprogress ) {
 	progressupdate( bytes, "" );
     }
@@ -496,6 +502,10 @@
 badline:
     exitval = 1;
 
+    if ( fclose( f ) != 0 ) {
+	fprintf( stderr, "%s: fclose failed: %s\n", path, strerror( errno ));
+    }
+
     if ( checkall ) {
 	goto done;
     } else {
