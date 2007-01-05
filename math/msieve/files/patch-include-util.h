--- include/util.h.orig	Sun Dec 31 16:30:03 2006
+++ include/util.h	Wed Jan  3 18:00:10 2007
@@ -43,7 +43,10 @@
 #include <math.h>
 #include <stdarg.h>
 #include <time.h>
-#ifndef _MSC_VER
+#include <osreldate.h>
+#if defined(FREEBSD) && (__FreeBSD_version < 500000)
+#include <inttypes.h>
+#elsif !defined(_MSC_VER)
 #include <stdint.h>
 #endif
 
