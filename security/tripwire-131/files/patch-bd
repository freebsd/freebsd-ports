--- src/utils.c.orig	Tue Jun 13 23:43:01 2000
+++ src/utils.c	Tue Jun 13 23:43:50 2000
@@ -856,8 +856,8 @@
     int fd;
 
     (void) strcpy(tmp, TEMPFILE_TEMPLATE);
-    if ((char *) mktemp(tmp) == NULL) {
-	perror("tempfilename_generate: mktemp()");
+    if (mkstemp(tmp) == -1) {
+	perror("tempfilename_generate: mkstemp()");
 	exit(1);
     }
 
