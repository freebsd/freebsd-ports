--- usr/lib/api/apiutil.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/api/apiutil.c
@@ -19,10 +19,10 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <dlfcn.h>
 #include <errno.h>
 #include <sys/syslog.h>
+#include <limits.h>
 
 #include <sys/ipc.h>
 
@@ -35,7 +35,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <sys/file.h>
 
 static int xplfd = -1;
 
