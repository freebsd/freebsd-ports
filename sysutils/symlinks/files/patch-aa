--- symlinks.c.orig	2010-01-23 09:58:35.000000000 -0800
+++ symlinks.c	2010-01-23 09:59:34.000000000 -0800
@@ -1,10 +1,6 @@
 #include <unistd.h>
-#ifndef _POSIX_SOURCE
-#define _POSIX_SOURCE
-#endif
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <string.h>
 #include <fcntl.h>
 #include <sys/param.h>
@@ -358,5 +354,5 @@
 	}
 	if (dircount == 0)
 		usage_error();
-	exit (0);
+	return (0);
 }
