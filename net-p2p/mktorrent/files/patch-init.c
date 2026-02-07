--- init.c.orig	2017-09-07 14:49:58 UTC
+++ init.c
@@ -512,10 +512,10 @@ EXPORT void init(metafile_t *m, int argc
 
 	/* set the correct piece length.
 	   default is 2^18 = 256kb. */
-	if (m->piece_length < 15 || m->piece_length > 28) {
+	if (m->piece_length < 15 || m->piece_length > 30) {
 		fprintf(stderr,
 			"The piece length must be a number between "
-			"15 and 28.\n");
+			"15 and 30.\n");
 		exit(EXIT_FAILURE);
 	}
 	m->piece_length = 1 << m->piece_length;
