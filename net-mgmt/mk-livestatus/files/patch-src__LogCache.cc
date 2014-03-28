PR ports/187433: fix build on FreeBSD 10 
========================================

--- ./src/LogCache.cc.orig	2014-03-16 19:32:30.000000000 +0100
+++ ./src/LogCache.cc	2014-03-16 19:33:20.000000000 +0100
@@ -25,6 +25,7 @@
 #include <time.h>
 #include <sys/types.h>
 #include <dirent.h>
+#include <pthread.h>
 #include <unistd.h>
 #include <stddef.h>
 #include <stdarg.h>
