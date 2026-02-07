--- mime.cpp.orig	2006-01-24 07:58:33 UTC
+++ mime.cpp
@@ -844,7 +844,8 @@ MIME_body:: AddPart(const char *file, in
 	char  line[BUFSIZ];
 	int   len, blen;
 	long  here;
-	char *boundary, *ptr;
+	const char *ptr;
+	char *boundary;
 	char *newcontent, *newencoding;
 
 	/* Open the input file */
