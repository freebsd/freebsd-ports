--- ./argcargv.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./argcargv.c	2014-06-29 12:15:04.243544285 +0200
@@ -48,7 +48,9 @@
 
     if ( acav == NULL ) {
 	if ( acavg == NULL ) {
-	    acavg = acav_alloc();
+	    if (( acavg = acav_alloc()) == NULL ) {
+		return( -1 );
+	    }
 	}
 	acav = acavg;
     }
