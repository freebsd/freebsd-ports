--- src/getopt.c.orig	2007-12-21 13:03:26.000000000 -0800
+++ src/getopt.c	2008-09-26 13:45:11.958473185 -0700
@@ -195,6 +195,8 @@
 /* gcc with -traditional declares the built-in strlen to return int,
    and has done so at least since version 2.4.5. -- rms.  */
 extern int strlen(const char *);
+#else
+#include <string.h>
 #endif				/* not __STDC__ */
 #endif				/* __GNUC__ */
 
