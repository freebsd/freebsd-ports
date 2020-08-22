--- freebsd/FreeBSDProcessList.h.orig	2018-04-10 13:42:59 UTC
+++ freebsd/FreeBSDProcessList.h
@@ -17,7 +17,7 @@ in the source distribution for its full text.
 #include <sys/resource.h>
 
 #define JAIL_ERRMSGLEN	1024
-char jail_errmsg[JAIL_ERRMSGLEN];
+extern char jail_errmsg[JAIL_ERRMSGLEN];
 
 typedef struct CPUData_ {
 
