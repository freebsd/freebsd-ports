--- filterdiff.c.orig	Fri Feb  1 19:21:43 2002
+++ filterdiff.c	Fri Feb  1 19:21:55 2002
@@ -24,6 +24,9 @@
 #include "config.h"
 #endif
 
+#ifdef HAVE_SYS_TYPES_H
+# include <sys/types.h> // for ssize_t
+#endif /* HAVE_SYS_TYPES_H */
 #ifdef HAVE_ERROR_H
 # include <error.h>
 #endif /* HAVE_ERROR_H */
@@ -34,9 +37,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#ifdef HAVE_SYS_TYPES_H
-# include <sys/types.h> // for ssize_t
-#endif /* HAVE_SYS_TYPES_H */
 #include <time.h>
 
 #include "util.h"
