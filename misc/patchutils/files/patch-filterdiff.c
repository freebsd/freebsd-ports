--- filterdiff.c.orig	Fri Mar 15 17:51:27 2002
+++ filterdiff.c	Fri Mar 15 17:52:32 2002
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
