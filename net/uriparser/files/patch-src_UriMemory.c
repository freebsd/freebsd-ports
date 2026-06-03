--- src/UriMemory.c.orig	2026-04-27 12:35:55 UTC
+++ src/UriMemory.c
@@ -66,6 +66,10 @@
 #  endif
 #endif
 
+/* Ensure BSD extensions like reallocarray are visible */
+#define __BSD_VISIBLE 1
+#define _DEFAULT_SOURCE 1
+
 #include <errno.h>
 #include <stdlib.h>
 
