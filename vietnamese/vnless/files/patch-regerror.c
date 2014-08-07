--- regerror.c.orig	Mon Feb 24 12:45:41 1992
+++ regerror.c	Wed Dec  4 02:42:23 1996
@@ -1,7 +1,9 @@
 #include <stdio.h>
+
+#ifdef FBSD_HAS_THIS_IN_LIBCOMPAT
 regerror(str)
 char *str;
 {
 /*	fprintf(stderr,"%s\n",str); */
 }
-
+#endif
