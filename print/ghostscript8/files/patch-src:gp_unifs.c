--- src/gp_unifs.c.orig	Tue Mar 13 15:51:39 2001
+++ src/gp_unifs.c	Wed Jun 20 04:06:02 2001
@@ -28,6 +28,7 @@
 #include "stat_.h"
 #include "dirent_.h"
 #include <sys/param.h>		/* for MAXPATHLEN */
+#include <unistd.h>
 
 /* Some systems (Interactive for example) don't define MAXPATHLEN,
  * so we define it here.  (This probably should be done via a Config-Script.)
@@ -58,6 +59,8 @@
 		     const char *mode)
 {				/* The -8 is for XXXXXX plus a possible final / and -. */
     int len = gp_file_name_sizeof - strlen(prefix) - 8;
+    int fd;
+    FILE *f;
 
     if (gp_gettmpdir(fname, &len) != 0)
 	strcpy(fname, "/tmp/");
@@ -70,8 +73,12 @@
     if (*fname != 0 && fname[strlen(fname) - 1] == 'X')
 	strcat(fname, "-");
     strcat(fname, "XXXXXX");
-    mktemp(fname);
-    return gp_fopentemp(fname, mode);
+    fd = mkstemp(fname);
+    if (fd == -1)
+	return NULL;
+    if ((f = fdopen(fd, mode)) == NULL)
+	close(fd);
+    return f;
 }
 
 /* Open a file with the given name, as a stream of uninterpreted bytes. */
