--- ../generic/tclexpat.c	2007-08-07 13:54:16.000000000 -0400
+++ ../generic/tclexpat.c	2008-02-14 14:35:48.000000000 -0500
@@ -43,4 +43,6 @@
 #ifdef _MSC_VER
 #include <io.h>
+#else
+#include <unistd.h>	/* read() and close() live there */
 #endif
 
