--- lib/pkfont.c.orig	1989-11-15 13:19:52.000000000 +0100
+++ lib/pkfont.c	2012-11-30 14:59:23.000000000 +0100
@@ -183,7 +183,7 @@
 /*
  * Skip over special commands (PK_XXX?, PK_YYY).
  */
-static
+static void
 skip_specials(f)
 	struct font *f;
 {
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
