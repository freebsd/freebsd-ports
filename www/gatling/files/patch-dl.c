--- dl.c.orig	2009-04-10 17:51:59.000000000 +0200
+++ dl.c	2009-04-10 17:56:31.000000000 +0200
@@ -37,6 +37,10 @@
 #include <assert.h>
 #include <ctype.h>
 #include <string.h>
+#include "havestrndup.h"
+#ifndef LIBC_HAS_STRNDUP
+char* strndup(const char*, size_t);
+#endif
 
 int dostats;
 
