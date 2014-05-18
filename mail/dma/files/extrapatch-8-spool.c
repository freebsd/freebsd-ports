--- spool.c	2013-06-03 14:03:15.000000000 +0000
+++ spool.c.8	2014-05-17 18:14:45.000000000 +0000
@@ -36,6 +36,7 @@
 
 #include <sys/file.h>
 #include <sys/stat.h>
+#include <sys/time.h>
 
 #include <ctype.h>
 #include <dirent.h>
@@ -415,7 +416,7 @@
 		return (0);
 
 	/* Did the flush file get touched within the last period seconds? */
-	if (st.st_mtim.tv_sec + period >= now.tv_sec)
+	if (st.st_mtime + (int)period >= now.tv_sec)
 		return (1);
 	else
 		return (0);
