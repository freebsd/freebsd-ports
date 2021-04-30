--- src/bin/lttng/commands/view.c.orig	2017-01-09 19:26:28 UTC
+++ src/bin/lttng/commands/view.c
@@ -17,6 +17,7 @@
 
 #define _LGPL_SOURCE
 #include <popt.h>
+#include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -269,7 +270,7 @@ static char *build_live_path(char *session_name)
 {
 	int ret;
 	char *path = NULL;
-	char hostname[HOST_NAME_MAX];
+	char hostname[_POSIX_HOST_NAME_MAX];
 
 	ret = gethostname(hostname, sizeof(hostname));
 	if (ret < 0) {
