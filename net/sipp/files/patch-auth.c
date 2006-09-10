$FreeBSD$

--- auth.c.orig	Tue Aug 29 11:03:34 2006
+++ auth.c	Thu Sep  7 22:54:05 2006
@@ -21,6 +21,9 @@
  * 				- introduced AKAv1-MD5
  */
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
