--- src/special_value.c.orig	2021-02-09 21:57:57 UTC
+++ src/special_value.c
@@ -27,6 +27,8 @@
 
 /* 'Special values' are strings parsed for xo-output */
 
+#include <sys/queue.h>
+
 #include <libxo/xo.h>
 #include <string.h>
 
