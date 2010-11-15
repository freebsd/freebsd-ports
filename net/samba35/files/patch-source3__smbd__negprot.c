--- ./source3/smbd/negprot.c.orig	2010-10-07 18:41:16.000000000 +0200
+++ ./source3/smbd/negprot.c	2010-11-14 03:46:55.000000000 +0100
@@ -34,7 +34,7 @@
 	if (sconn->smb1.negprot.auth_context) {
 		DEBUG(3, ("get challenge: is this a secondary negprot? "
 			  "sconn->negprot.auth_context is non-NULL!\n"));
-			sconn->smb1.negprot.auth_context->free(
+			(sconn->smb1.negprot.auth_context->free)(
 				&sconn->smb1.negprot.auth_context);
 	}
 
