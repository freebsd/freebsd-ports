--- src/filterdiff.c.orig	Thu May  9 01:50:58 2002
+++ src/filterdiff.c	Thu May  9 22:03:24 2002
@@ -24,12 +24,12 @@
 #include "config.h"
 #endif
 
-#ifdef HAVE_ERROR_H
-# include <error.h>
-#endif /* HAVE_ERROR_H */
 #ifdef HAVE_SYS_TYPES_H
 # include <sys/types.h> // for ssize_t
 #endif /* HAVE_SYS_TYPES_H */
+#ifdef HAVE_ERROR_H
+# include <error.h>
+#endif /* HAVE_ERROR_H */
 #include <fnmatch.h>
 #include <getopt.h>
 #include <locale.h>
