--- tclUnixPipe.c.orig	Tue Nov 30 09:43:03 1999
+++ tclUnixPipe.c	Wed Nov 14 09:09:20 2001
@@ -185,8 +185,8 @@
     char fileName[L_tmpnam];
     int fd;
 
-    tmpnam(fileName);					/* INTL: Native. */
-    fd = open(fileName, O_RDWR|O_CREAT|O_TRUNC, 0666);	/* INTL: Native. */
+    strlcpy(fileName, "/var/tmp/tcltmp.XXXXXX", L_tmpnam);
+    fd = mkstemp(fileName);				/* INTL: Native. */
     if (fd == -1) {
 	return NULL;
     }
