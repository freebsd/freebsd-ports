--- ./mkdirs.c.orig	2010-12-12 22:42:49.000000000 -0500
+++ ./mkdirs.c	2012-03-20 14:38:08.000000000 -0400
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
