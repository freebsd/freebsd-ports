--- lib/pkfont.c.orig	Wed Nov 15 13:19:52 1989
+++ lib/pkfont.c	Wed Dec 13 23:01:34 2006
@@ -781,8 +781,8 @@
 	if (pk != NULL) {
 		free(pk->pk_base); pk -> pk_base = 0;
 		if (pk->pk_morec != NULL) {
-		  free((char *) pk->pk_morec); (char *) pk->pk_morec = 0;
+		  free((char *) pk->pk_morec); pk->pk_morec = 0;
 		}
-		free((char *) pk); (char *) pk = 0;
+		free((char *) pk); pk = 0;
 	}
 }
