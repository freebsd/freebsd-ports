--- tclUnixPipe.c.orig	Wed Apr  4 00:54:39 2001
+++ tclUnixPipe.c	Thu May 10 22:00:30 2001
@@ -195,10 +195,8 @@
      * We should also check against making more then TMP_MAX of these.
      */
 
-    if (tmpnam(fileName) == NULL) {			/* INTL: Native. */
-	return NULL;
-    }
-    fd = open(fileName, O_RDWR|O_CREAT|O_EXCL, 0666);	/* INTL: Native. */
+    strlcpy(fileName, "/var/tmp/tcltmp.XXXXXX", L_tmpnam);
+    fd = mkstemp(fileName);				/* INTL: Native. */
     if (fd == -1) {
 	return NULL;
     }
