--- dictP.h.orig	Wed Feb 25 02:55:51 2004
+++ dictP.h	Mon Aug  2 18:23:15 2004
@@ -50,6 +50,9 @@
 #if HAVE_ALLOCA_H
 # include <alloca.h>
 #else
+#ifdef __FreeBSD__
+# include <stdlib.h>
+#else
 # ifdef _AIX
 # pragma alloca
 # else
@@ -59,6 +62,7 @@
 #  endif
 #  endif
 # endif
+#endif
 #endif
 
 /* Get string functions */
