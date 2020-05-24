diff -r -u a/alloc.c b/alloc.c
--- alloc.c 1998-06-15 03:53:16.000000000 -0700
+++ alloc.c 2020-05-04 16:43:32.923310325 -0700
@@ -1,3 +1,4 @@
+#include <limits.h>
 #include "alloc.h"
 #include "error.h"
 extern char *malloc();
@@ -15,6 +16,10 @@
 unsigned int n;
 {
   char *x;
+  if (n >= (INT_MAX >> 3)) {
+    errno = error_nomem;
+    return 0;
+  }
   n = ALIGNMENT + n - (n & (ALIGNMENT - 1)); /* XXX: could overflow */
   if (n <= avail) { avail -= n; return space + avail; }
   x = malloc(n);
