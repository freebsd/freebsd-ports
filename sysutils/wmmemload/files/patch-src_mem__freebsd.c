--- src/mem_freebsd.c.orig	2015-04-17 12:23:47 UTC
+++ src/mem_freebsd.c
@@ -10,6 +10,7 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
