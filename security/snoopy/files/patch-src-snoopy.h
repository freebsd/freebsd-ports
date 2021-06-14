--- src/snoopy.h.orig	2021-02-09 23:00:14 UTC
+++ src/snoopy.h
@@ -31,8 +31,6 @@
 /* This must be the first file to be included, or implicit inclusion
  * (by i.e. <features.h>) does the wrong thing
  */
-#define  _XOPEN_SOURCE   700
-#include <features.h>   /* Needed for GLIBC macros here */
 #include <syslog.h>     /* Needed for syslog defaults */
 #include <unistd.h>
 
