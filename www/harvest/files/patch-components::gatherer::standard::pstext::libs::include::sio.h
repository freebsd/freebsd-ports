--- ./components/gatherer/standard/pstext/libs/include/sio.h.orig	Fri Aug  1 14:20:17 2003
+++ ./components/gatherer/standard/pstext/libs/include/sio.h	Fri Aug  1 14:20:27 2003
@@ -12,7 +12,11 @@
 #define __SIO_H
 
 #include <errno.h>
+#ifdef __STRICT_ANSI__
+#include <stdarg.h>
+#else
 #include <varargs.h>
+#endif
 
 /*
  * Naming conventions:
