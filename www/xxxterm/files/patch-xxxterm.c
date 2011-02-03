--- ./xxxterm.c.orig	2011-01-20 10:45:02.893061548 +0200
+++ ./xxxterm.c	2011-01-20 10:45:18.001973993 +0200
@@ -36,13 +36,13 @@
 #include <pwd.h>
 #include <string.h>
 #include <unistd.h>
-#include <util.h>
 #include <pthread.h>
 #include <dlfcn.h>
 #include <errno.h>
 
 #include <sys/types.h>
 #if defined(__linux__)
+	#include <util.h>
 	#include "linux/util.h"
 	#include "linux/tree.h"
 #elif defined(__FreeBSD__)
