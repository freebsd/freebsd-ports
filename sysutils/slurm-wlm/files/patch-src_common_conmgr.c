--- src/common/conmgr.c.orig	2023-11-21 22:33:29 UTC
+++ src/common/conmgr.c
@@ -47,6 +47,8 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#include <sys/param.h>
+#include <sys/ucred.h>
 #include <time.h>
 #include <unistd.h>
 
