--- jabberd/mtq.c.orig	Tue Jul  6 19:18:05 2004
+++ jabberd/mtq.c	Tue Jul  6 19:18:29 2004
@@ -127,7 +127,7 @@
     while(1) {
 
 		if  (t->mtq->last == NULL ) {
-		  Sleep(1);
+		  Sleep(500);
 		}
 
 		
