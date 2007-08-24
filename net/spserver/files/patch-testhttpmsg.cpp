--- spserver/testhttpmsg.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/testhttpmsg.cpp	Thu Aug 23 07:33:58 2007
@@ -76,7 +76,7 @@
 		//printf( "%d, %d\n", i, parsedLen );
 	}
 
-	printf( "source length : %d, parsed length : %d\n", strlen( source ), parsedLen );
+	printf( "source length : %d, parsed length : %d\n", (int)strlen( source ), parsedLen );
 
 	printf( "parse complete : %s\n", parser.isCompleted() ? "Yes" : "No" );
 
