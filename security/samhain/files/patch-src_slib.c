--- src/slib.c.orig	2019-01-17 20:05:33 UTC
+++ src/slib.c
@@ -18,12 +18,14 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <string.h>
+#include <strings.h>
 #include <limits.h>
 #ifdef HAVE_STDINT_H
 /* for SIZE_MAX */
 #include <stdint.h>
 #endif
 
+#include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
