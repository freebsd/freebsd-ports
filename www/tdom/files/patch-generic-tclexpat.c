--- generic/tclexpat.c.orig	2008-03-04 20:34:28 UTC
+++ generic/tclexpat.c
@@ -42,6 +42,8 @@
 
 #ifdef _MSC_VER
 #include <io.h>
+#else
+#include <unistd.h>	/* read() and close() live there */
 #endif
 
 #ifdef _POSIX_SOURCE
