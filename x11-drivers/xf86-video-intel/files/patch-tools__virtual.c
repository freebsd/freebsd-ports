--- tools/virtual.c.orig	2023-02-01 18:07:58 UTC
+++ tools/virtual.c
@@ -69,6 +69,10 @@
 #include <fcntl.h>
 #include <assert.h>
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 #define FORCE_FULL_REDRAW 0
 #define FORCE_16BIT_XFER 0
 
