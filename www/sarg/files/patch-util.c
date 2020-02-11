--- util.c.orig	2020-02-11 12:29:43 UTC
+++ util.c
@@ -27,6 +27,9 @@
 // #define LEGACY_MY_ATOLL
 // #define LEGACY_TESTVALIDUSERCHAR
 
+#include <sys/param.h>
+#include <sys/stat.h>
+
 #include "include/conf.h"
 #include "include/defs.h"
 
@@ -402,7 +405,7 @@ int is_absolute(const char *path)
 
 int PortableMkDir(const char *path,int mode)
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	int mkerror=mkdir(path,mode);
 #else //mingw
 	(void)mode;
