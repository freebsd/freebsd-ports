--- src/datasource/snoopy_version.c.orig	2016-09-14 15:02:26 UTC
+++ src/datasource/snoopy_version.c
@@ -30,7 +30,6 @@
 #include "snoopy.h"
 
 #ifndef   _XOPEN_SOURCE   /* Needed to get getpgid and getsid on older glibc */
-#define   _XOPEN_SOURCE   500
 #endif
 #include <stdio.h>
 #include <sys/types.h>
