--- ./source3/smbd/server.c.orig	2010-10-26 02:55:21.000000000 +0200
+++ ./source3/smbd/server.c	2010-10-26 02:55:54.000000000 +0200
@@ -841,7 +841,7 @@
 
 	if (sconn && sconn->smb1.negprot.auth_context) {
 		struct auth_context *a = sconn->smb1.negprot.auth_context;
-		a->free(&sconn->smb1.negprot.auth_context);
+		(a->free)(&sconn->smb1.negprot.auth_context);
 	}
 
 	if (sconn) {
