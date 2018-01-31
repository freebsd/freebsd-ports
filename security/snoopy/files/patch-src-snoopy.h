--- src/snoopy.h.orig	2016-09-14 15:02:26 UTC
+++ src/snoopy.h
@@ -31,11 +31,6 @@
 /* This must be the first file to be included, or implicit inclusion
  * (by i.e. <features.h>) does the wrong thing
  */
-#ifdef   _XOPEN_SOURCE
-#undef   _XOPEN_SOURCE
-#endif
-#define  _XOPEN_SOURCE   500
-#include <features.h>   /* Needed for GLIBC macros here */
 #include <syslog.h>     /* Needed for syslog defaults */
 #include <unistd.h>     /* Needed for _SC_ARG_MAX constant */
 
