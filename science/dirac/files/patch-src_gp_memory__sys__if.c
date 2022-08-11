--- src/gp/memory_sys_if.c.orig	2022-08-10 06:55:50 UTC
+++ src/gp/memory_sys_if.c
@@ -37,6 +37,8 @@
 #include <errno.h>
 #include <string.h>
 
+#include <sys/types.h>
+
 #include "trace.h"
 
 #define FORTRAN_STRx_TO_INT8(a) (int64_t)strtol(a,NULL,16)
