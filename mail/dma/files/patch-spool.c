--- ./spool.c.orig	2010-08-10 17:48:35.000000000 +0200
+++ ./spool.c	2010-08-11 18:59:57.113889734 +0200
@@ -92,7 +92,7 @@
 	 */
 	if (fstat(fd, &st) != 0)
 		goto fail;
-	if (asprintf(&queue->id, "%"PRIxMAX, st.st_ino) < 0)
+	if (asprintf(&queue->id, "%"PRIxMAX, (uintmax_t)st.st_ino) < 0)
 		goto fail;
 
 	queue->mailf = fdopen(fd, "r+");
