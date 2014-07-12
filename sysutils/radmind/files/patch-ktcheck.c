--- ./ktcheck.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./ktcheck.c	2014-06-29 12:15:04.245544128 +0200
@@ -459,7 +459,7 @@
 	perror( "Incorrect number of arguments\n" );
 	return( 2 );
     }
-    times.modtime = atoi( targv[ 5 ] );
+    times.modtime = strtotimet( targv[ 5 ], NULL, 10 );
     times.actime = time( NULL );
 
     if (( stat( path, &st )) != 0 ) {
@@ -506,7 +506,7 @@
 		needupdate = 1;
 	    }
 	} else {
-	    if ( atoi( targv[ 5 ] ) != (int)st.st_mtime )  {
+	    if ( strtotimet( targv[ 5 ], NULL, 10 ) != st.st_mtime )  {
 		needupdate = 1;
 	    }
 	}
