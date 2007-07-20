--- ./src/encoding.c.orig	2007-07-20 13:49:39.000000000 +0400
+++ ./src/encoding.c	2007-07-20 13:50:00.000000000 +0400
@@ -97,7 +97,7 @@
 int i;
 
 	if (str==NULL) return NULL;
-	if (buf_len<(strlen(str)+1)){
+	if (buf_len<(strlen(str)*2+1)){
 		buf_len=strlen(str)*2+1; /* this should always be enough */
 		buf=(char *)g_realloc(buf,buf_len);
 		assert(buf!=NULL);
