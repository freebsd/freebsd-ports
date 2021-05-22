--- include/fd.h.orig	2021-05-21 21:31:28 UTC
+++ include/fd.h
@@ -26,6 +26,7 @@
 
 #include <stdbool.h>
 #include <stdlib.h>		/* for ssize_t */
+#include <sys/types.h>
 
 #include "where.h"
 
