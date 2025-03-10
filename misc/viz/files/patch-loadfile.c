--- loadfile.c.orig
+++ loadfile.c
@@ -1,9 +1,8 @@
+#include <errno.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/fcntl.h>
-
-extern errno;
 
 char *loadfile(path)
 char *path;
