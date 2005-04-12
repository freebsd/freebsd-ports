
$FreeBSD$

--- shs.h.orig
+++ shs.h
@@ -1,7 +1,9 @@
+#include <inttypes.h>
+
 typedef struct {
-    long totalLength;
-    unsigned long h[5];
-    unsigned long w[80];
+    int32_t totalLength;
+    uint32_t h[5];
+    uint32_t w[80];
 } SHS_CTX;
 
 unsigned char *qshs();
