--- src/common/util.c.orig	Sun May  2 01:29:20 2004
+++ src/common/util.c	Sat May 29 15:19:02 2004
@@ -25,6 +25,7 @@
 #include <windows.h>
 #endif
 
+#include <sys/param.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -56,7 +57,9 @@
 #include <sys/limits.h>
 #endif
 #ifdef HAVE_MACHINE_LIMITS_H
+#ifndef __FreeBSD__
 #include <machine/limits.h>
+#endif
 #endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h> /* Must be included before sys/stat.h for Ultrix */
