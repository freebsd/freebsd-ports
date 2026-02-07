--- src/mem.c.orig	2019-07-31 06:49:48 UTC
+++ src/mem.c
@@ -23,6 +23,7 @@
 
 #include <stdlib.h>
 #include "mem.h"
+#include "err.h"
 
 void *
 mem_malloc (unsigned int size, bool_t crit)
