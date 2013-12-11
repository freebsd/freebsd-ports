--- mup/grpsyl.c.orig	2013-12-11 23:55:33.069603514 +0400
+++ mup/grpsyl.c	2013-12-11 23:56:52.275555216 +0400
@@ -2107,7 +2107,7 @@
 		if (list_p->str != S_STAFF) {
 			/* Do error check like in check4missing_voices() */
 			if (Errorcount > 0) {
-				return;
+				return(0);
 			}
 			else {
 				pfatal("proc_emptymeas: info about staff %d not in list", s);
