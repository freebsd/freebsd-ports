--- src/file.c.orig	Fri Jan  9 09:16:19 1998
+++ src/file.c	Sat Sep  7 16:51:54 2002
@@ -4,6 +4,7 @@
 
 #include "global.h"
 #include <sys/stat.h>
+#include <paths.h>
 #include "expand.h"
 #include "file.h"
 
@@ -185,16 +186,18 @@
 int create_temp_fd(char **name)
 {
     int	fd;
-
-    *name = tmpnam(NULL);
-    if (!*name)
-	fd = -1;
-    else {
-	unlink(*name);
-	fd = open(*name, O_RDWR|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
-	if (fd < 0)
-	    *name = NULL;
-    }
+    char filename[FILENAME_MAX];
+    char *tmpdir;
+ 
+    if ((tmpdir = getenv("TMPDIR")) == NULL)
+	tmpdir = _PATH_TMP;
+    strlcpy(filename, tmpdir, FILENAME_MAX);
+    strlcat(filename, "/tmp.XXXXXX", FILENAME_MAX); 
+	
+    if ((fd = mkstemp(filename)) == -1)
+	*name = NULL;
+    else
+        *name = filename;
 
     return fd;
 }
