--- icap/icap.c.orig	Tue Jan 28 18:31:33 2003
+++ icap/icap.c	Tue Mar 20 21:49:33 2007
@@ -159,7 +159,7 @@
 	if (!reopen) {
 		if ((stream = calloc(1, sizeof(*stream))) == NULL)
 			goto fail;
-		if ((DATA = calloc(1, sizeof(*DATA))) == NULL)
+		if ((stream->data = calloc(1, sizeof(*DATA))) == NULL)
 			goto fail;
 
 		/* Copy host. */
