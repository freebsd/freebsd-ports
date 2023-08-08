--- config.c.orig	2023-01-06 17:56:22 UTC
+++ config.c
@@ -21,6 +21,7 @@
 #include <errno.h>
 #include <getopt.h>
 #include <unistd.h>
+#include <sys/syslimits.h>
 
 #include "genimage.h"
 
@@ -259,7 +260,7 @@ static char *abspath(const char *path)
 	if (*path == '/')
 		return strdup(path);
 
-	xasprintf(&p, "%s/%s", get_current_dir_name(), path);
+	xasprintf(&p, "%s/%s", getcwd(NULL, PATH_MAX), path);
 
 	return p;
 }
