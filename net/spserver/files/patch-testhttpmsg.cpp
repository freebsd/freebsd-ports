--- testhttpmsg.cpp.orig	Mon Jun 18 12:46:36 2007
+++ testhttpmsg.cpp	Mon Jun 18 12:47:00 2007
@@ -76,7 +76,7 @@
 		//printf( "%d, %d\n", i, parsedLen );
 	}
 
-	printf( "source length : %d, parsed length : %d\n", strlen( source ), parsedLen );
+	printf( "source length : %d, parsed length : %d\n", (int)strlen( source ), parsedLen );
 
 	printf( "parse complete : %s\n", parser.isCompleted() ? "Yes" : "No" );
 
