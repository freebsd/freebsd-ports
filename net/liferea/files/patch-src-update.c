--- src/update.c.orig	Mon Jun 28 00:23:19 2004
+++ src/update.c	Fri Jul  2 10:17:30 2004
@@ -91,8 +91,8 @@
 }
 
 void download_process(struct request *request) {
-	request->data = NULL;
 	FILE *f;
+	request->data = NULL;
 	
 	if(request->source[0] == '|') {
 		/* if the first char is a | we have a pipe else a file */
