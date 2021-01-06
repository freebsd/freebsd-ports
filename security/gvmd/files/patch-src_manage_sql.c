--- src/manage_sql.c	2020-08-11 10:05:36.000000000 -0500
+++ src/manage_sql.c	2021-01-04 17:08:05.732803000 -0500
@@ -51,7 +51,6 @@
 #include <dirent.h>
 #include <errno.h>
 #include <glib/gstdio.h>
-#include <malloc.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <sys/socket.h>
@@ -15276,7 +15275,7 @@
 
   cleanup_iterator (&nvts);
 
-  malloc_trim (0);
+ // malloc_trim (0);
 }
 
 /**
