--- usr/lib/pkcs11/api/apiutil.c.orig	2016-04-29 17:26:45 UTC
+++ usr/lib/pkcs11/api/apiutil.c
@@ -298,10 +298,10 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <dlfcn.h>
 #include <errno.h>
 #include <sys/syslog.h>
+#include <limits.h>
 
 #include <sys/ipc.h>
 
@@ -314,7 +314,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <sys/file.h>
 
 static int xplfd = -1;
 
