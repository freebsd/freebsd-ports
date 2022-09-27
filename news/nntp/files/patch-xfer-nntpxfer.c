--- xfer/nntpxfer.c.orig	1996-01-09 07:28:03 UTC
+++ xfer/nntpxfer.c
@@ -547,12 +556,14 @@ char *articleid;
 	int len;
 #endif
 	char id[BUFSIZ];
+#ifndef CNEWS
 	char *p;
+#endif
 
 	/* remove any case sensitivity */
 	(void) strcpy(id, articleid);
-	p = id;
 #ifndef CNEWS
+	p = id;
 	while (*p)
 		{
 		if (isupper(*p))
