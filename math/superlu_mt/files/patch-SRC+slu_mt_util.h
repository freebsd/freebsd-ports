--- SRC/slu_mt_util.h~	2008-01-09 08:28:56.000000000 +0900
+++ SRC/slu_mt_util.h	2008-07-02 09:54:31.000000000 +0900
@@ -12,6 +12,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <pthread.h>
 
 /* Macros */
 #ifndef USER_ABORT
