--- find_nonzero.h.orig	2014-01-18 17:32:44.000000000 +0900
+++ find_nonzero.h	2014-01-18 17:33:03.000000000 +0900
@@ -12,6 +12,7 @@
 
 #include <string.h>
 #include <sys/types.h>
+#include <stdint.h>
 
 #ifdef HAVE_FFS
 # define myffs(x) ffs(x)
