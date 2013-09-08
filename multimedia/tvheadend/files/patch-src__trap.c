--- src/trap.c.orig	2013-07-26 18:17:22.000000000 +0200
+++ src/trap.c	2013-09-01 16:07:04.247691694 +0200
@@ -33,6 +33,7 @@
 #include <limits.h>
 #if ENABLE_EXECINFO
 #include <execinfo.h>
+#include <dlfcn.h>
 #endif
 #include <stdio.h>
 #include <stdarg.h>
@@ -47,6 +48,7 @@
 
 #define MAXFRAMES 100
 
+extern char **environ;
 static char line1[200];
 static char tmpbuf[1024];
 static char libs[1024];
