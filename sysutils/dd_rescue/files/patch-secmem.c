--- secmem.c.orig	2021-05-04 08:16:41 UTC
+++ secmem.c
@@ -10,6 +10,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/mman.h>
+#include <stddef.h>
 #ifdef HAVE_MALLOC_H
 # include <malloc.h>
 #endif
