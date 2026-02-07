--- src/datasource/sid.c.orig	2020-12-06 01:59:36 UTC
+++ src/datasource/sid.c
@@ -30,7 +30,6 @@
 #include "snoopy.h"
 
 #ifndef   _XOPEN_SOURCE   /* Needed to get getpgid and getsid on older glibc */
-#define   _XOPEN_SOURCE   500
 #endif
 #include <stdio.h>
 #include <sys/types.h>
