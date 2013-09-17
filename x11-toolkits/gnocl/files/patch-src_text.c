--- src/text.c.orig	2013-08-31 12:36:08.000000000 +0200
+++ src/text.c	2013-09-17 10:07:27.000000000 +0200
@@ -3267,7 +3267,7 @@
 	if ( tag == NULL )
 	{
 
-		return TCL_ERROR;
+		return;
 	}
 
 
@@ -3299,8 +3299,6 @@
 
 	sprintf ( s1, "" );
 	sprintf ( s2, "" );
-
-	return TCL_OK;
 }
 
 
