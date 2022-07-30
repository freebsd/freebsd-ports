--- find_nonzero_sse2.c.orig	2022-07-25 15:45:07 UTC
+++ find_nonzero_sse2.c
@@ -5,6 +5,7 @@
  */
 
 #include "find_nonzero.h"
+#include "ffs.h"
 
 #if defined(__x86_64__) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__)
 
