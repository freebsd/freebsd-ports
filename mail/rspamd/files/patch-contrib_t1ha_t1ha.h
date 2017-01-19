--- contrib/t1ha/t1ha.h.orig	2017-01-19 10:58:36 UTC
+++ contrib/t1ha/t1ha.h
@@ -44,6 +44,9 @@
 #include <string.h>
 #include <stddef.h>
 
+#ifndef __has_attribute
+#define __has_attribute(x) (0)
+#endif
 #ifndef __has_builtin
 #define __has_builtin(x) (0)
 #endif
