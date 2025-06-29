--- include/forkserver.h.orig	2025-06-28 20:29:37 UTC
+++ include/forkserver.h
@@ -30,6 +30,8 @@
 
 #include <stdio.h>
 #include <stdbool.h>
+#include <string.h>
+#include <unistd.h>
 
 #include "types.h"
 
