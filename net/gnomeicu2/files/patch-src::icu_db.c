
$FreeBSD$

--- src/icu_db.c.orig	Sat Jun 22 22:11:46 2002
+++ src/icu_db.c	Wed Sep 11 11:45:05 2002
@@ -27,7 +27,11 @@
 
 #include <fcntl.h>
 #include <errno.h>
+#if defined(HAVE_STDLIB_H)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <sys/param.h>
