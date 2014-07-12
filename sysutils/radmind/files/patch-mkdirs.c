--- ./mkdirs.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./mkdirs.c	2014-06-29 12:15:04.247544144 +0200
@@ -37,7 +37,9 @@
 	if ( mkdir( path, 0777 ) == 0 ) {
 	    break;
 	}
-	if ( errno != ENOENT ) {
+	if ( errno == EEXIST ) {
+	    break;
+	} else if ( errno != ENOENT ) {
 	    return( -1 );
 	}
 	q = p;
