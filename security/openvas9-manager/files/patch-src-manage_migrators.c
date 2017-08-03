--- src/manage_migrators.c.orig	2015-08-03 05:52:13 UTC
+++ src/manage_migrators.c
@@ -122,6 +122,7 @@
 /* time.h in glibc2 needs this for strptime. */
 #define _XOPEN_SOURCE
 
+#include <sys/wait.h>
 #include <time.h>
 #include <stdlib.h>
 #include <string.h>
