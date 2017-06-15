--- src/env.c.orig	2017-03-05 22:10:09 UTC
+++ src/env.c
@@ -2080,7 +2080,7 @@ static void confCGI(Connection *Conn,DYC
 	if( *ereq ){
 		putenv(ereq);
 	}
-	if( 0 <= esock ){
+	if( esock != NULL ){
 		sprintf(esock,"CLSOCK=%d",ClientSock);
 		putenv(esock);
 	}
