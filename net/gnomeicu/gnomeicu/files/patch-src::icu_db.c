--- src/icu_db.c.orig	Sat Jan  5 19:15:03 2002
+++ src/icu_db.c	Sat Jan  5 19:16:00 2002
@@ -33,7 +33,11 @@
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(HAVE_STDLIB_H)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #if defined(HAVE_LIBGDBM)
 #include <gdbm.h>
