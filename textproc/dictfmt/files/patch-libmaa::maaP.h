--- libmaa/maaP.h.orig	Sun Oct 26 22:03:24 2003
+++ libmaa/maaP.h	Mon Aug  2 18:28:34 2004
@@ -37,6 +37,9 @@
 #if HAVE_ALLOCA_H
 # include <alloca.h>
 #else
+#ifdef __FreeBSD__
+# include <stdlib.h>
+#else
 # ifdef _AIX
 #  pragma alloca
 # else
@@ -44,6 +47,7 @@
     char *alloca ();
 #  endif
 # endif
+#endif
 #endif
 
 /* Get string functions */
