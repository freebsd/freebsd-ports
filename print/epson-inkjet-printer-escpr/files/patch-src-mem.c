--- src/mem.c.orig	2014-09-08 02:02:44 UTC
+++ src/mem.c
@@ -24,6 +24,7 @@
 
 #include <stdlib.h>
 #include "mem.h"
+#include "err.h"
 
 void *
 mem_malloc (unsigned int size, bool_t crit)
