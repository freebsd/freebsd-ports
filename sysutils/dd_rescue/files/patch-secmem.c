--- secmem.c.orig	2024-08-22 17:41:01 UTC
+++ secmem.c
@@ -11,6 +11,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/mman.h>
+#include <stddef.h>
 #ifdef HAVE_MALLOC_H
 # include <malloc.h>
 #endif
