--- attr.c.orig	2022-11-17 12:28:15 UTC
+++ attr.c
@@ -7,6 +7,8 @@
 
 #include "config.h"
 
+#include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <rpc/rpc.h>
