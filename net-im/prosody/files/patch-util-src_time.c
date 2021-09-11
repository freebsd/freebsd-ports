--- util-src/time.c.orig	2021-08-03 09:53:04 UTC
+++ util-src/time.c
@@ -1,7 +1,3 @@
-#ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 199309L
-#endif
-
 #include <time.h>
 #include <lua.h>
 
